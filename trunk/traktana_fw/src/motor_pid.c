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
/* Variables required for ADC configuration */
unsigned int Channel, PinConfig, Scanselect;
unsigned int Adcon3_reg, Adcon2_reg, Adcon1_reg;

/* This is ADCInterrupt routine for PID DC Motor Control*/
void __attribute__((interrupt, no_auto_psv)) _ADCInterrupt(void)
{
//        int i = 0;
char ptr[15];
//		fooPID.measuredOutput = Q15(ReadADC12(0));
/*        while (i < 3)
        {
           controlHistory[i] = ReadADC12(i);i++;
        }
*/
		sprintf(&ptr,"\nRead: %d",ReadADC12(0));
		putsUART1("Teste!");
//		PID(&fooPID);
		//SetDCOC1PWM(fooPID.controlOutput);
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
        fooPID.controlHistory = &controlHistory[0];     /*Set up pointer to controller history samples */
        PIDInit(&fooPID);                               /*Clear the controler history and the controller output */
		kCoeffs[0] = Q15(0.7);
		kCoeffs[1] = Q15(0.2);
		kCoeffs[2] = Q15(0.07);
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


		/* Configure ADC Channel */
//	    Channel = ADC_CH0_POS_SAMPLEA_AN4 &  
//    	          ADC_CH0_NEG_SAMPLEA_VREFN &
//        	      ADC_CH0_POS_SAMPLEB_AN2& 
//            	  ADC_CH0_NEG_SAMPLEB_AN1;
//	    SetChanADC12(Channel);
		/* Configure ADC Interrupt */
    	ConfigIntADC12(ADC_INT_ENABLE & ADC_INT_PRI_0);
		/* Configure ADC Registers */
	    Adcon3_reg = ADC_SAMPLE_TIME_10 &
    	             ADC_CONV_CLK_SYSTEM &
        	         ADC_CONV_CLK_13Tcy;

	    Adcon2_reg = ADC_VREF_AVDD_AVSS &
    	             ADC_SCAN_OFF &
					 ADC_ALT_BUF_OFF &
            	     ADC_ALT_INPUT_OFF & 
                	 ADC_SAMPLES_PER_INT_3;

	    Adcon1_reg = ADC_MODULE_ON &
    	             ADC_IDLE_CONTINUE &
        	         ADC_FORMAT_INTG &
            	     ADC_CLK_MPWM  &
                	 ADC_AUTO_SAMPLING_ON;

		/* Configure ADC Input Pins */
    	PinConfig  = ENABLE_AN12_ANA;
    	Scanselect = SCAN_NONE;

		/* Apply ADC Configurations */
	    OpenADC12(Adcon1_reg, Adcon2_reg,
    	          Adcon3_reg,PinConfig, Scanselect);
        
		//Clear the A/D interrupt flag bit
        IFS0bits.ADIF = 0;
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
