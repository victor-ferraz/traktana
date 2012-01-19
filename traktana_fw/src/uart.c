#include "p30fxxxx.h"
#include <uart.h>
#include <string.h>
#include <stdio.h>

/*****************************************************************************/

#define SWITCH(a) {char *_p = a; if (0) 
#define CASE(x, s) } else if (memcmp(_p, x, s) == 0) {
#define DEFAULT } else {
#define ENDSWITCH }}

/*****************************************************************************/

#define UART_BUFFER_SIZE	20

char buf[UART_BUFFER_SIZE]; /*__attribute__ ((section("uartbuf"), address(0x88C)));*/
char *wbufptr = buf;
char *rbufptr = buf;
unsigned int bufstt = (unsigned int)&buf;
//unsigned int bufstt __attribute__ ((persistent)); 
unsigned char cmdissued = 0;
unsigned char cmdblocked = 0;
unsigned char adc_readout = 0;


//-------------------------------------------
// Extern Global Variables and functions to control the program
extern unsigned char stepper_enable1,stepper_enable2;
extern unsigned char direction1,direction2,mode_step1,mode_step2;
extern void step_stepper1();
extern void step_stepper2();
extern void disable_stepper1();
extern void disable_stepper2();


/* This is UART1 receive ISR */
/* Implements a Ring Buffer */ 
void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void) 
{
    IFS0bits.U1RXIF = 0;

	//Maybe it is a good idea to rip off the while below and receive just one byte per interrupt,
	//as we do not want that the ISR take too long. Also we won't receive burst data because
    //the UART is intended to receive user's terminal input.
    while(DataRdyUART1())
    {
		//If buffer is full or command not processed yet,
		if ((wbufptr==((char*)bufstt+UART_BUFFER_SIZE)) || (cmdissued == 1))
			//Discard char... So, 'write pointer' won't over run. 
			ReadUART1();
		else
			//Save char and increment buffer
 			*wbufptr++ = ReadUART1();
	}
}  

void loopback_UART(void)
{
	if (rbufptr==((char*)bufstt+UART_BUFFER_SIZE)) //Do not let it over run
	{
		rbufptr = (char*)bufstt;
		wbufptr = rbufptr;	//sync pointers
	}
	else if ((wbufptr > rbufptr) && (cmdissued == 0))
	{
		//if char is not an 'escape' and 'cmd' is not blocked,
		//echo char back.
		if ((*rbufptr != 0x1B) && (cmdblocked == 0)) 
			putcUART1(*rbufptr);

		switch(*rbufptr++)
		{
			case 0x08: //Backspace
				if (rbufptr > ((char*)bufstt+1)) //Do not let it under run.
				{
					putcUART1(' ');
					putcUART1(0x08);
					rbufptr-=2;
					//wbufptr-=2;		//deprecated as we're sync'ing below
					wbufptr = rbufptr;	//sync pointers
				}
				else
				{
					rbufptr--;
					wbufptr = rbufptr;	//sync pointers
				}
				break;
			
			case 0x1B: //Escape
				if (cmdblocked == 1){
					adc_readout	= 0;
					cmdblocked	= 0;
					rbufptr		= (char*)bufstt;
					wbufptr 	= rbufptr;	//sync pointers
					putsUART1((unsigned int *)"\n\nFinished!\n\n\r");
				}
				break;
			
			case 0x0A: //New Line	
				//PORTAbits.RA9		= !PORTAbits.RA9;
				//TRISAbits.TRISA9	= 0;
				break;	
			
			case 0x0D: //Carriage Return	
				if (cmdblocked == 0){
					putcUART1(0x0A);
					rbufptr		= (char*)bufstt;
					wbufptr 	= rbufptr;	//sync pointers
					cmdissued	= 1;
				}
				break;	
			
		}
    	while(BusyUART1()); 
	}
}

// Converts a string containing a real number ranging from 0.0 to 9.9 into 8.8 fixed point integer.
unsigned int ato88(char *s)
{
	unsigned int n = 0;

	if (s[1] != '.') return 0;

	switch(*s++)
	{
		case '0': n = 0 << 8; break;
		case '1': n = 1 << 8; break;
		case '2': n = 2 << 8; break;
		case '3': n = 3 << 8; break;
		case '4': n = 4 << 8; break;
		case '5': n = 5 << 8; break;
		case '6': n = 6 << 8; break;
		case '7': n = 7 << 8; break;
		case '8': n = 8 << 8; break;
		case '9': n = 9 << 8; break;
		default : n = 0 << 8; break;
	}

	switch(*++s)
	{
		case '0': n = n;	  					 break;
		case '1': n = n + (((1 << 8) + 5) / 10); break;
		case '2': n = n + (((2 << 8) + 5) / 10); break;
		case '3': n = n + (((3 << 8) + 5) / 10); break;
		case '4': n = n + (((4 << 8) + 5) / 10); break;
		case '5': n = n + (((5 << 8) + 5) / 10); break;
		case '6': n = n + (((6 << 8) + 5) / 10); break;
		case '7': n = n + (((7 << 8) + 5) / 10); break;
		case '8': n = n + (((8 << 8) + 5) / 10); break;
		case '9': n = n + (((9 << 8) + 5) / 10); break;
		default : n = 0; 	  					 break;
	}

	return n;
}

/*
unsigned char memcmp(char *s1, char *s2, unsigned int size)
{
	unsigned int i = 0;

	for(i = 0; i<size; i++)
		if(*s1++ != *s2++) return 1;
	
	return 0; 
}
*/

void process_cmd(void)
{
	char goodcmd[]	= "- Command Accepted.\n\n\r\0";
	char evilcmd[]	= "- BAD Command.\n\n\r\0";

	char *r = evilcmd;
	

	if (cmdissued == 1)
	{
		SWITCH(rbufptr)
		{
//***************************************************************************//
			//*** sng: single ***//
			CASE("sng ", 4){
				putsUART1((unsigned int *)"sng ");
				rbufptr+=4;
				if (*rbufptr == '1'){
					stepper_enable1=0;
					step_stepper1();
					r = goodcmd;
				}else if (*rbufptr == '2'){
					stepper_enable2=0;
					step_stepper2();
					r = goodcmd;				
				}else{
					r = evilcmd;
				}
			}
			//*** sts: start ***//
			CASE("sts ", 4){
				putsUART1((unsigned int *)"sts ");
				rbufptr+=4;
				if (*rbufptr == '1'){
					stepper_enable1=1;
					r = goodcmd;
				}else if (*rbufptr == '2'){
					stepper_enable2=1;
					r = goodcmd;				
				}else{
					r = evilcmd;
				}
			}
			//*** stp: stop ***//
			CASE("stp ", 4){
				putsUART1((unsigned int *)"stp ");
				rbufptr+=4;
				if (*rbufptr == '1'){
					stepper_enable1=0;
					r = goodcmd;
				}else if (*rbufptr == '2'){
					stepper_enable2=0;
					r = goodcmd;				
				}else{
					r = evilcmd;
				}
			}
			//*** stmf: full ***//
			CASE("stmf ", 5){
				putsUART1((unsigned int *)"stmf ");
				rbufptr+=5;
				if (*rbufptr == '1'){
					mode_step1=1;
					r = goodcmd;
				}else if (*rbufptr == '2'){
					mode_step2=1;
					r = goodcmd;				
				}else{
					r = evilcmd;
				}
			}
			//*** stmh: half ***//
			CASE("stmh ", 5){
				putsUART1((unsigned int *)"stmh ");
				rbufptr+=5;
				if (*rbufptr == '1'){
					mode_step1=0;
					r = goodcmd;
				}else if (*rbufptr == '2'){
					mode_step2=0;
					r = goodcmd;				
				}else{
					r = evilcmd;
				}
			}
			//*** stdc: clockwise ***//
			CASE("stdc ", 5){
				putsUART1((unsigned int *)"stdc ");
				rbufptr+=5;
				if (*rbufptr == '1'){
					direction1=1;
					r = goodcmd;
				}else if (*rbufptr == '2'){
					direction2=1;
					r = goodcmd;				
				}else{
					r = evilcmd;
				}
			}
			//*** stdh: counter clockwise ***//
			CASE("stdh ", 5){
				putsUART1((unsigned int *)"stdh ");
				rbufptr+=5;
				if (*rbufptr == '1'){
					direction1=0;
					r = goodcmd;
				}else if (*rbufptr == '2'){
					direction2=0;
					r = goodcmd;				
				}else{
					r = evilcmd;
				}
			}
			//*** std: disable ***//
			CASE("std ", 4){
				putsUART1((unsigned int *)"std ");
				rbufptr+=4;
				if (*rbufptr == '1'){
					stepper_enable1=0;
					disable_stepper1();
					r = goodcmd;
				}else if (*rbufptr == '2'){
					stepper_enable2=0;
					disable_stepper2();
					r = goodcmd;				
				}else{
					r = evilcmd;
				}
			}
//***************************************************************************//
			//*** adc: adc readout ***//
			CASE("adc", 3){
				putsUART1((unsigned int *)"adc ");
				cmdblocked = 1;
				adc_readout = 1;
				r = goodcmd;
			}
//***************************************************************************//
			DEFAULT
				r = evilcmd;

		ENDSWITCH


		rbufptr	= (char*)bufstt;
		wbufptr = rbufptr;

		putsUART1((unsigned int *)r);
		while(BusyUART1());

		cmdissued = 0;
	}
}

void echo_UART(void)
{	
	char ptr[20];	
	if (adc_readout == 1){
		sprintf(ptr,"0x%04X\r",ADCBUF0);
		putsUART1((unsigned int *)ptr);
		while(BusyUART1());
	}
}

int Init_UART(void)
{
	//OSCTUN = 0x09;

/* Turn off UART1module */
    //CloseUART1();

/* Configure uart1 receive and transmit interrupt */
    ConfigIntUART1(UART_RX_INT_EN & UART_RX_INT_PR5 &  
                   UART_TX_INT_DIS & UART_TX_INT_PR0);

	U1MODE	= 0x8000;
	U1STA	= 0x0400;
	// Baud Rate = FCY/(16*(U1BRG+1))
	// or U1BRG = (FCY/16*Baud Rate) - 1
	// if Baud Rate = 115200 and FCY = 30M then 
	//	U1BRG = (30M/16*115200) - 1
	//	U1BRG = 15,276
	U1BRG	= 15;

    return 0;
}
