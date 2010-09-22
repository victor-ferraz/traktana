/**********************************************************************
* © 2010 GG Technology Inc.
* FileName:        main.c
* Dependencies:    Header (.h) files if applicable, see below
* Processor:       dsPIC30F4013/3012
* Compiler:        MPLAB® C30 v3.00 or higher
* IDE:             MPLAB® IDE v7.52 or later
* Dev. Board Used: dsPICTraktana Board
* Hardware Dependencies: None
*
**********************************************************************/

#include <dsp.h>

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
Main function demonstrating the use of PID(), PIDInit() and PIDCoeffCalc()
functions from DSP library in MPLAB C30 v3.00 and higher
*/
int main (void)
{
/*
Step 1: Initialize the PID data structure, fooPID
*/
        fooPID.abcCoefficients = &abcCoefficient[0];    /*Set up pointer to derived coefficients */
        fooPID.controlHistory = &controlHistory[0];     /*Set up pointer to controller history samples */
        PIDInit(&fooPID);                               /*Clear the controler history and the controller output */
	kCoeffs[0] = Q15(0.7);
	kCoeffs[1] = Q15(0.2);
	kCoeffs[2] = Q15(0.07);
        PIDCoeffCalc(&kCoeffs[0], &fooPID);             /*Derive the a,b, & c coefficients from the Kp, Ki & Kd */

/*
Step 2: Use the PID Controller
*/
        fooPID.controlReference = Q15(0.74) ;           /*Set the Reference Input for your controller */
        fooPID.measuredOutput = Q15(0.453) ;            /*Typically the measuredOutput variable is a plant response*/
                                                        /*measured from an A/D input or a sensor. */
                                                        /*In this example we manually set it to some value for */
                                                        /*demonstration but the user should note that this value will */
                                                        /*keep changing in a real application*/
        while (1)                                       /*We use a while(1) loop here for demonstration purposes.*/
        {                                               /*Typically, the PID calculation may be triggered off a timer*/
                                                        /*or A/D interrupt */

                PID(&fooPID);                           /*Call the PID controller using the new measured input */
                                                        /*The user may place a breakpoint on "PID(&fooPID)", halt the debugger,*/
                                                        /*tweak the measuredOutput variable within the watch window */
                                                        /*and then run the debugger again */
        }

}
