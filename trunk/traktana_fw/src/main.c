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
#include <p30fxxxx.h>            //standard header file

//---------------------------------------------------------------------------
// Variables

//---------------------------------------------------------------------------
// Prototypes
void InitDevice();
int  Init_UART(void);
void loopback_UART(void);
void process_cmd(void);
void Init_Steppers();
void Motor_PID_Init (void);
//---------------------------------------------------------------------------
// Main routine
int main(void)
{
	InitDevice();
    while(1) 	//Loop forever
    {
		loopback_UART();
		process_cmd();
    }
}
//--------------------------------------------------------------------------------------------------------------
// Init all necessary functions
void InitDevice(){
	Init_UART();
	Init_Steppers();
	Motor_PID_Init();
}
