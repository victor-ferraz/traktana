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
void step_stepper1();
void Motor_PID_Init (void);
//---------------------------------------------------------------------------
//Variables
unsigned long freq=200000;
int slope = 0;
//---------------------------------------------------------------------------
//Main routine

int main(void)
{
	InitDevice();
    while(1) 	//Loop forever
    {
//		loopback_UART();
//		process_cmd();
    }
}

void InitDevice(){
	TRISB = 0x00; 	// configure PORTB for output (STEPPERS)
	ADPCFG = 0xFFF;	// configure PORTB for digital output
	//init_UART();
	init_Steppers();
}
