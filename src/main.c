/*********************************************************************
 *
 *              dsPIC30F3014/dsPIC30F4013 Traktana Source Code
 *
 *********************************************************************
 * FileName:        main.c
 * Dependencies:    p30F3014.h or p30F4013.h                 
 * Date:            11/10/2010
 * Processor:       dsPIC30F3014/dsPIC30F4013
 * Complier:        MPLAB C30
 * Company:         Centro Brasileiro de Pesquisas Físicas
 *
 * Software License Agreement: Creative Commons
 *
 * Authors               Date       Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Victor Ferraz         11/10/2010  Original        (Rev 1.0)
 *
 ********************************************************************/

#include <p30F3014.h>            //Standard header file

//---------------------------------------------------------------------------
//Prototypes
void InitDevice();
int init_UART(void);
void loopback_UART(void);
void process_cmd(void);

//---------------------------------------------------------------------------
//Variables
int out_stepper = 0x01;
unsigned long i=200000;
int slope = 0;
//---------------------------------------------------------------------------
//Main routine

int main(void)
{
	InitDevice();
    while(1) 	//Loop forever
    {
       	LATB = out_stepper;
	   	if(out_stepper > 0x04){
			out_stepper = 0x01;
		}else{
			out_stepper = out_stepper << 1;
		}
		// 1 instruction = 1/117,92M =~ 8,5 ns
		__delay32(i);		// 1K*8,5ns = 	8,5ms

		loopback_UART();
		process_cmd();
    }
}

void InitDevice(){
	TRISB = 0x00; 	// configure PORTB for output (STEPPERS)
	ADPCFG = 0xFFF;	// configure PORTB for digital output
	init_UART();
}
