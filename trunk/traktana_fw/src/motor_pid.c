#include <dsp.h>
#include<outcompare.h>

/*
Variable Declaration required for each PID controller in your application
*/
/* Declare a PID Data Structure named, fooPID */
tPID fooPID;
/* The fooPID data structure contains a pointer to derived coefficients in X-space and */
/* pointer to controler state (history) samples in Y-space. So declare variables for the */
/* derived coefficients and the controller history samples */
fractional abcCoefficient[3] __attribute__ ((section (".xbss, bss, xmemory")));
fractional controlHistory[3] __attribute__ ((section (".ybss, bss, ymemory")));
/* The abcCoefficients referenced by the fooPID data structure */
/* are derived from the gain coefficients, Kp, Ki and Kd */
/* So, declare Kp, Ki and Kd in an array */
fractional kCoeffs[] = {0,0,0};

/*
Motor_PID_Init function performing the use of PID(), PIDInit() and PIDCoeffCalc()
functions from DSP library in MPLAB C30 v3.00 and higher
*/
void Motor_PID_Init (void)
{
/*
Initialize the PID data structure, fooPID
*/
        fooPID.abcCoefficients = &abcCoefficient[0];    /*Set up pointer to derived coefficients */
        fooPID.controlHistory = &controlHistory[0];     /*Set up pointer to controller history samples */
        PIDInit(&fooPID);                               /*Clear the controler history and the controller output */
		kCoeffs[0] = Q15(0.7);
		kCoeffs[1] = Q15(0.2);
		kCoeffs[2] = Q15(0.07);
        PIDCoeffCalc(&kCoeffs[0], &fooPID);             /*Derive the a,b, & c coefficients from the Kp, Ki & Kd */
/*
Initialize the PWM and ADC peripherals
*/
		/* Configure output compare1 interrupt off */
		ConfigIntOC1(OC_INT_OFF & OC_INT_PRIOR_5);
		/* Configure Output Compare module to 'initialise OCx pin
			low and pwm mode using Timer3 */
    	OpenOC1(OC_TIMER3_SRC&OC_PWM_FAULT_PIN_DISABLE,0x00,0x00);
/*
Use the PID Controller
*/
        fooPID.controlReference = Q15(0.74) ;           /*Set the Reference Input for your controller */
        fooPID.measuredOutput = Q15(0.453) ;            /*Typically the measuredOutput variable is a plant response*/
                                                        /*measured from an A/D input or a sensor. */
                                                        /*In this example we manually set it to some value for */
                                                        /*demonstration but the user should note that this value will */
                                                        /*keep changing in a real application*/
//        while (1)                                       /*We use a while(1) loop here for demonstration purposes.*/
//        {                                               /*Typically, the PID calculation may be triggered off a timer*/
//                                                        /*or A/D interrupt */
//
//                PID(&fooPID);                           /*Call the PID controller using the new measured input */
//                                                        /*The user may place a breakpoint on "PID(&fooPID)", halt the debugger,*/
//                                                        /*tweak the measuredOutput variable within the watch window */
//                                                        /*and then run the debugger again */
//        }

}
