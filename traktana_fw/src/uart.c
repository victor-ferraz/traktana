#include "p30fxxxx.h"
#include <uart.h>
#include <string.h>
#include <outcompare.h>

#define UART_BUFFER_SIZE	20

char buf[UART_BUFFER_SIZE]; /*__attribute__ ((section("uartbuf"), address(0x88C)));*/
char *wbufptr = buf;
char *rbufptr = buf;
unsigned int bufstt = (unsigned int)&buf;
//unsigned int bufstt __attribute__ ((persistent)); 

unsigned char cmdissued = 0;

//unsigned int bufadr = (unsigned int)&buf;

//-------------------------------------------
// Extern Global Variables and functions to control the program
extern unsigned char stepper_enable1,stepper_enable2;
extern unsigned char direction1,direction2,mode_step1,mode_step2;
extern void disable_stepper1();
extern void disable_stepper2();

/* This is UART1 receive ISR */
/* Implements a Ring Buffer */ 
void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void) 
{
    IFS0bits.U1RXIF = 0;

	//Maybe it is good idea to rip off the while below and receive just one byte per interrupt,
	//as we do not want that the ISR take too long. Also we won't receive burst data because
    //the UART is intended to receive user's terminal input.
    while(DataRdyUART1())
    {
		//If we receive a 'new line' char, a command was issued.
		//if (ReadUART1() == '\n') cmdissued = 1;

		//If we receive a 'backspace' char, we HAVE TO DO SOMETHING!
		//

		//If buffer is full or command not processed yet,
		if ((wbufptr==((char*)bufstt+UART_BUFFER_SIZE)) || (cmdissued == 1))
			//Discard char... 
			ReadUART1();
		else
			//Save char and increment buffer
 			*wbufptr++ = ReadUART1();

		//if (wbufptr==((char*)bufstt+UART_BUFFER_SIZE)) wbufptr = (char*)bufstt;
	}
}  



void loopback_UART(void)
{
	if (rbufptr==((char*)bufstt+UART_BUFFER_SIZE)) //Do not let it over run
	{
		rbufptr = (char*)bufstt;
		//wbufptr = (char*)bufstt;
		wbufptr = rbufptr;	//sync pointers
	}
	else if ((wbufptr > rbufptr) && (cmdissued == 0))
	{
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
					//PORTAbits.RA9		= !PORTAbits.RA9;
					//TRISAbits.TRISA9	= 0;
				}
				else
				{
					rbufptr--;
					wbufptr = rbufptr;	//sync pointers
				}
				break;

			case 0x0A: //New Line	
				//PORTAbits.RA9		= !PORTAbits.RA9;
				//TRISAbits.TRISA9	= 0;
				break;	
			
			case 0x0D: //Carriage Return	
				putcUART1(0x0A);
				rbufptr		= (char*)bufstt;
				//wbufptr		= (char*)bufstt;
				wbufptr 	= rbufptr;	//sync pointers
				cmdissued	= 1;

				//PORTAbits.RA9		= !PORTAbits.RA9;
				//TRISAbits.TRISA9	= 0;
				break;	
			
		}
    	while(BusyUART1()); 
	}

	//if (rbufptr==((char*)bufstt+UART_BUFFER_SIZE-1)) rbufptr = (char*)bufstt;
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

void process_cmd(void)
{
	char goodcmd[]	= "- Command Accepted.\n\n\r\0";
	char evilcmd[]	= "- BAD Command.\n\n\r\0";

	char *r = evilcmd;

	if (cmdissued == 1)
	{
		switch(*rbufptr++)
		{
		/*** STEPPER COMMANDS ***/
			case 's':
				putcUART1('s');
				if(*rbufptr++ == 't'){
					putcUART1('t');
					switch(*rbufptr++){
						case 's':{
							putcUART1('s');
							// sts command received (start)
							if(*rbufptr++ == ' '){
								// sts parameters [1 or 2]
								if(*rbufptr == '1'){
									r = goodcmd;stepper_enable1=1;
								}else if(*rbufptr++ == '2'){
									r = goodcmd;stepper_enable2=1;
								}	
							}
						}break;
						case 'p':{
							putcUART1('p');
							// stp command received (stop)
							if(*rbufptr++ == ' '){
								// stp parameters [1 or 2]
								if(*rbufptr == '1'){
									r = goodcmd;stepper_enable1=0;
								}else if(*rbufptr++ == '2'){
									r = goodcmd;stepper_enable2=0;
								}	
							}
						}break;
						case 'd':{
							putcUART1('d');
							// std command received (disable)
							if(*rbufptr == ' '){
								*rbufptr++;
								// std parameters [1 or 2]
								if(*rbufptr == '1'){
									r = goodcmd;disable_stepper1();
								}else if(*rbufptr++ == '2'){
									r = goodcmd;disable_stepper2();
								}	
							}else{
								switch(*rbufptr++){
									// stdc command received (direction clockwise)
									case 'c':{
									 if(*rbufptr++ == ' '){
										// stdc parameters [1 or 2]
										if(*rbufptr == '1'){
											r = goodcmd;direction1=1;
										}else if(*rbufptr++ == '2'){
											r = goodcmd;direction2=1;
										}
									 }
									}break;	
									// stdh command received (direction counter clockwise)
									case 'h':{
									 if(*rbufptr++ == ' '){
										// stdh parameters [1 or 2]
										if(*rbufptr == '1'){
											r = goodcmd;direction1=0;
										}else if(*rbufptr++ == '2'){
											r = goodcmd;direction2=0;
										}
									 }
									}break;	
								}
							}
						}break;
						case 'm':{
							putcUART1('m');
								switch(*rbufptr++){
									// stmf command received (Full Step Mode)
									case 'f':{
									 if(*rbufptr++ == ' '){
										// stdc parameters [1 or 2]
										if(*rbufptr == '1'){
											r = goodcmd;mode_step1=1;
										}else if(*rbufptr++ == '2'){
											r = goodcmd;mode_step2=1;
										}
									 }
									}break;	
									// stmh command received (Half Step Mode)
									case 'h':{
									 if(*rbufptr++ == ' '){
										// stdh parameters [1 or 2]
										if(*rbufptr == '1'){
											r = goodcmd;mode_step1=0;
										}else if(*rbufptr++ == '2'){
											r = goodcmd;mode_step2=0;
										}
									 }
									}break;	
								}
						}break;
						case 'f':{
							putcUART1('f');
							r = goodcmd;
						}break;
						// invalid command
						default: r = evilcmd;break;
					}
				}
			break;
			/*** DC MOTOR COMMANDS ***/
			case 'm':
				putcUART1('m');
				if(*rbufptr++ == 'd'){
					putcUART1('d');
					if(*rbufptr++ == 'c'){
						putcUART1('c');
						switch(*rbufptr++){
							case 'r':{
								putcUART1('r');
								// mdcr command received (start)
								if(*rbufptr++ == ' '){
									// mdcr parameters []
									r = goodcmd; SetDCOC1PWM(*rbufptr);
								}
							}break;
							case 'p':{
								putcUART1('p');
								// mdcp command received (start)
								if(*rbufptr++ == ' '){
									// mdcp parameters []
									
								}
							}break;
							case 'i':{
								putcUART1('i');
								// mdci command received (start)
								if(*rbufptr++ == ' '){
									// mdci parameters []
									
								}
							}break;
							case 'd':{
								putcUART1('d');
								// mdcd command received (start)
								if(*rbufptr++ == ' '){
									// mdcd parameters []
									
								}
							}break;
						}
					}
				}
			break;
		}

		rbufptr	= (char*)bufstt;
		wbufptr = rbufptr;

		putsUART1((unsigned int *)r);
		while(BusyUART1());

		cmdissued = 0;
	}
}

int Init_UART(void)
{
//OSCTUN = 0x09;

/* Turn off UART1module */
    //CloseUART1();

/* Configure uart1 receive and transmit interrupt */
    ConfigIntUART1(UART_RX_INT_EN & UART_RX_INT_PR6 &  
                   UART_TX_INT_DIS & UART_TX_INT_PR0);

/* Configure UART1 module to transmit 8 bit data with one stopbit. Also Enable loopback mode  */ 
    /*
	baudvalue = 64;

    U1MODEvalue =	UART_EN & 
					UART_IDLE_CON &
					UART_IrDA_DISABLE &
					UART_RX_TX &
					UART_DIS_WAKE & 
					UART_DIS_LOOPBACK &
					UART_DIS_ABAUD & 
					UART_NO_PAR_8BIT  &
					UART_1STOPBIT & 
					UART_BRGH_FOUR &
					UART_UXRX_IDLE_ONE;

    U1STAvalue =	UART_INT_TX_BUF_EMPTY &
					UART_TX_ENABLE &
					UART_INT_RX_CHAR &
					UART_ADR_DETECT_DIS &
					UART_RX_OVERRUN_CLEAR;

    OpenUART1(U1MODEvalue, U1STAvalue, baudvalue);
*/
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
