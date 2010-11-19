#ifndef __dsPIC30F3014__
#define __dsPIC30F3014__
#endif

#include "p30f3014.h"
#include <uart.h>
#include <string.h>

#define UART_BUFFER_SIZE	20

char buf[UART_BUFFER_SIZE]; /*__attribute__ ((section("uartbuf"), address(0x88C)));*/
char *wbufptr = buf;
char *rbufptr = buf;
unsigned int bufstt = (unsigned int)&buf;
//unsigned int bufstt __attribute__ ((persistent)); 

unsigned char cmdissued = 0;

//unsigned int bufadr = (unsigned int)&buf;

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
	char vusage[]	= "- Usage: v [channel (0-1)] [voltage (1.0 - 7.0)]\n\n\r\0";
	char cinval[]	= "- Invalid Channel.\n\n\r\0";

	char *r = evilcmd;
	char value[4];

	if (cmdissued == 1)
	{
		/*
		while(*rbufptr != 0x0D)
		{
			putcUART1(*rbufptr++);
			while(BusyUART1());
		}
		rbufptr	= (char*)bufstt;
		wbufptr = rbufptr;
		*/

		switch(*rbufptr++)
		{

			/*** VOLTAGE SET ***/

			case 'v':
				/******************/	
				//putcUART1('V');
				//while(BusyUART1());
				/******************/

				if ((*rbufptr == '\r') || (*rbufptr == '\n'))
					r = vusage;

				//Param 0 - Channel
			
				else if (*rbufptr++ == ' ')
				{
					switch(*rbufptr++)
					{
						//Channel 0
						case '0':

							//Param 1 - Voltage

							if (*rbufptr++ == ' ')
							{
								//memcpy(value, rbufptr, 3);
					
								//__asm__ ("bclr.b  IEC0+1,#3");

								//PIDJ0_desired_voltage = 
									(unsigned int) ((ato88(value) * 0xCC9AL) >> 16);

								//PIDJ0_integral_error = 0;

								//__asm__ ("bset.b  IEC0+1,#3");

								//value[3] = '\0';
								//putsUART1 ((unsigned int *)value);
								//while(BusyUART1());
								r = goodcmd;
							}
							else
								r = vusage;
						break;
	
						//Channel 1
						case '1':

							//Param 1 - Voltage

							if (*rbufptr++ == ' ')
							{
								//memcpy(value, rbufptr, 3);
					
								//PIDJ1_desired_voltage = 
									//(unsigned int) ((ato88(value) * 0xCC9AL) >> 16);
								
								r = goodcmd;
							}
							else
								r = vusage;
						break;

						//Invalid Channel
						default:
							r = cinval;
						break;	
					}
				}
				else
					r = evilcmd;
			break;
			
			/*** CURRENT SET ***/

			case 'i':
				putcUART1('I');
				while(BusyUART1());
			break;
			
		}

		rbufptr	= (char*)bufstt;
		wbufptr = rbufptr;

		putsUART1((unsigned int *)r);
		while(BusyUART1());

		cmdissued = 0;
	}
}

int init_UART(void)
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
