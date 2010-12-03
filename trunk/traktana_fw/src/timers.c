#include "p30f3014.h"
#include <timer.h>

// Timer2 Interrupt routine
void __attribute__((interrupt, no_auto_psv)) _T2Interrupt(void){

//	step_stepper1();
	IFS0bits.T2IF = 0;       /* clear interrupt flag     */
	return;
}
// Timer3 Interrupt routine
void __attribute__((interrupt, no_auto_psv)) _T3Interrupt(void){

	step_stepper1();
	IFS0bits.T3IF = 0;       /* clear interrupt flag     */
	return;
}

void init_Timers(){

/* Enable Timer2 Interrupt and Priority to "1" */
    ConfigIntTimer2(T2_INT_PRIOR_1 & T2_INT_ON);

    OpenTimer2(T2_ON & T2_GATE_OFF & T2_PS_1_8 & 
			 	T2_SOURCE_INT, 0xFFFF);

/* Enable Timer3 Interrupt and Priority to "1" */
    ConfigIntTimer3(T3_INT_PRIOR_1 & T3_INT_ON);

    OpenTimer3(T3_ON & T3_GATE_OFF & T3_PS_1_8 
				 & T3_SOURCE_INT, 0xFFFF);

}
