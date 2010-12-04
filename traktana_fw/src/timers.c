#include "p30f3014.h"
#include <timer.h>

// Timer1 Interrupt routine
void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void){

	step_stepper1();
	IFS0bits.T1IF = 0;       /* clear interrupt flag     */
	return;
}
// Timer3 Interrupt routine
void __attribute__((interrupt, no_auto_psv)) _T2Interrupt(void){

	step_stepper2();
	IFS0bits.T2IF = 0;       /* clear interrupt flag     */
	return;
}

void init_Timers(){

/* Enable Timer1 Interrupt and Priority to "1" */
    ConfigIntTimer1(T1_INT_PRIOR_1 & T1_INT_ON);

    OpenTimer1(T1_ON & T1_GATE_OFF & T1_PS_1_8 & 
			 	T1_SOURCE_INT, 0xFFFF);

/* Enable Timer2 Interrupt and Priority to "1" */
    ConfigIntTimer2(T2_INT_PRIOR_1 & T2_INT_ON);

    OpenTimer2(T2_ON & T2_GATE_OFF & T2_PS_1_8 
				 & T2_SOURCE_INT, 0xFFFF);

}
