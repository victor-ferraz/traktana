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
#include <p30f3014.h>            //standard header file

//---------------------------------------------------------------------------
// Variables
// Global Variables (Stepper Motor control with timers)
//unsigned char stepper_enable1=0,stepper_enable2=0;
//unsigned char direction1=1,direction2=1,mode_step1=0,mode_step2=0;
//unsigned long frequency1,frequency2;
//---------------------------------------------------------------------------
// Prototypes
void InitDevice();
int  Init_UART(void);
void loopback_UART(void);
void process_cmd(void);
void Init_Steppers();
void Motor_PID_Init (void);
//--------------------------------------------------------------------------------------------------------------
//// Timer1 Interrupt routine for stepper 1
//void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void){
//
//	if(stepper_enable1) step_stepper1();
//	IFS0bits.T1IF = 0;       /* clear interrupt flag     */
//	return;
//}
////--------------------------------------------------------------------------------------------------------------
//// Timer3 Interrupt routine for stepper 2
//void __attribute__((interrupt, no_auto_psv)) _T2Interrupt(void){
//
//	step_stepper2();
//	IFS0bits.T2IF = 0;       /* clear interrupt flag     */
//	return;
//}
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
}
