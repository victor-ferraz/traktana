#include <dsp.h>
#include <outcompare.h>
#include <timer.h>
#include <adc12.h>
#include <uart.h>
#include <stdio.h>
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

/* This is ADCInterrupt routine for PID DC Motor Control*/
void __attribute__((interrupt, no_auto_psv)) _ADCInterrupt (void)
{
//        int i = 0;
//unsigned char ptr[15];
		fooPID.measuredOutput = ReadADC12(0);
/*        while (i < 3)
        {
           controlHistory[i] = ReadADC12(i);i++;
        }
*/
//		sprintf(&ptr,"\n\rRead: %X",ADCBUF0);
//		putsUART1(ptr);
		PID(&fooPID);
		SetDCOC1PWM((unsigned int)(fooPID.controlOutput*4095));

        //Clear the A/D Interrupt flag bit or else the CPU will
        //keep vectoring back to the ISR
        IFS0bits.ADIF = 0;
}


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
        fooPID.controlHistory  = &controlHistory[0];     /*Set up pointer to controller history samples */
        PIDInit(&fooPID);                               /*Clear the controler history and the controller output */
		kCoeffs[0] = Q15(0.3);		// Kp
		kCoeffs[1] = Q15(0.2);		// Ki
		kCoeffs[2] = Q15(0.0);		// Kd
        PIDCoeffCalc(&kCoeffs[0], &fooPID);             /*Derive the a,b, & c coefficients from the Kp, Ki & Kd */
/*
Initialize the PWM and ADC peripherals

PWM Frequency = 1/[PWM Period]
PWM Period = [(PR3) + 1] • TCY • (TMR3 Prescale Value)

PWM Frequency = 5KHz
PWM Period = 1/5K = 0,2ms
TCY = 1/3 * 10^-7M = 30 ns
(TMR3 Prescale Value) = 8
PR3 = [PWM Period/(TCY • TMR3 Prescale Value)] - 1
PR3 = [2 * 10^-4/(1/3 * 10^-7 * 8)] - 1
PR3 = [6 * 10^-4/(1 * 10^-7 * 8)] - 1 
PR3 = [6/8 * 10^3] - 1
PR3 = [0,75 * 10^3] - 1
PR3 = 750 - 1 = 749

Choosing others values:
PWM Frequency 			= 7.32KHz
(TMR3 Prescale Value) 	= 1
PR3						= 0x0FFF
Resolution				= 12 bits

*/
		/* Enable Timer3 Interrupt and Priority to "1" */
    	ConfigIntTimer3(T3_INT_PRIOR_1 & T3_INT_OFF);
    	OpenTimer3(T3_ON & T3_GATE_OFF & T3_IDLE_STOP &
               T3_PS_1_1 & T3_SOURCE_INT, 0x0FFF);

		/* Turn off OC1 module */
    	CloseOC1();
		/* Configure output compare1 interrupt off */
		ConfigIntOC1(OC_INT_OFF & OC_INT_PRIOR_5);
		/* Configure Output Compare module to 'initialise OCx pin
			low and pwm mode using Timer3 */
    	OpenOC1(OC_TIMER3_SRC&OC_PWM_FAULT_PIN_DISABLE,0x00,0x00);


		/* Start ADC Configuration */

        //ADCON1 Register
        //Set up A/D for Automatic Sampling
        //Use internal counter (SAMC) to provide sampling time
        //Set up A/D conversrion results to be read in unsigned integer format.
        //Set up Sequential sampling for multiple S/H amplifiers
        //All other bits to their default state
        ADCON1bits.FORM = 0;
        ADCON1bits.SSRC = 7;
        ADCON1bits.ASAM = 1;

        //ADCON2 Register
        //Set up A/D for interrupting after 16 samples get filled in the buffer
        //All other bits to their default state
        ADCON2bits.SMPI = 15;

        //ADCON3 Register
        //We will set up the ADRC as the A/D conversion clock
        //so that the A/D converter can operate when the device is in
        //SLEEP mode. Also, 1 Tad period is allocated for sampling time.
        //The conversion rate for the ADRC oscillator is depends on whether
        //the device is a dsPIC30F or dsPIC33F device and also whether the
        //A/D module is a 10-bit or 12-bit A/D converter.
        //Please refer to the device Datasheet for "ADRC" conversion rate.
        ADCON3bits.SAMC = 31;		// defines Tsample = Tad/32
		ADCON3bits.ADCS = 63;		// defines Tad = 1,06us	
        ADCON3bits.ADRC = 0;	

        //ADCHS Register
        //Set up A/D Channel Select Register to convert AN12 on Mux A input
        //of CH0 S/H amplifiers
        ADCHS = 0x000C;

        //ADCSSL Register
        //Channel Scanning is disabled. All bits left to their default state
        ADCSSL = 0x0000;

        //ADPCFG Register
        //Set up channels AN12 as analog input and configure rest as digital
        TRISB |= 0x1000;
		ADPCFG = 0xFFFF;
        ADPCFGbits.PCFG12 = 0;

        //Clear the A/D interrupt flag bit
        IFS0bits.ADIF = 0;

        //Set the A/D interrupt enable bit
        IEC0bits.ADIE = 1;

        //Turn on the A/D converter
        //This is typically done after configuring other registers
        ADCON1bits.ADON = 1;

/*
Initial PID Controller
*/
//        fooPID.controlReference = Q15(0.74) ;           /*Set the Reference Input for your controller */
//        fooPID.measuredOutput = Q15(0.453) ;            /*Typically the measuredOutput variable is a plant response*/

		fooPID.controlReference = 0x000A;           	/*Set the Reference Input for your controller */
        fooPID.measuredOutput 	= 0x00;
}

