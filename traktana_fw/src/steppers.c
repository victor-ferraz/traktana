#include "p30fxxxx.h"
#include <timer.h>

#define STEPPERS_PORT 		LATB
#define STEPPERS_TRIS 		TRISB
#define MAIN_SWITCH			PORTBbits.RB8
#define HALF_MODE			0
#define FULL_MODE			1
#define COUNTER_CLOCK_WISE	0
#define CLOCK_WISE			1
//#define SENSORS
//--------------------------------------------------------------------------------------------------------------
// Global Variables (Motor control with timers and more)
unsigned char stepper_enable1=0,stepper_enable2=0;
unsigned char direction1=1,direction2=1,mode_step1=0,mode_step2=0;
unsigned long frequency1,frequency2;
// Local Variables and contants
int pos_stepper1 = 0;
int pos_stepper2 = 0;
const unsigned char step_full1[4]= {0b11110001,
									0b11110010,
									0b11110100,
									0b11111000};

const unsigned char step_half1[8] ={0b11110001,
									0b11110011,
									0b11110010,
									0b11110110,
									0b11110100,
									0b11111100,
									0b11111000,
									0b11111001};


const unsigned char step_full2[4]= {0b00011111,
									0b00101111,
									0b01001111,
									0b10001111};

const unsigned char step_half2[8]= {0b00011111,
									0b00111111,
									0b00101111,
									0b01101111,
									0b01001111,
									0b11001111,
									0b10001111,
									0b10011111};
//--------------------------------------------------------------------------------------------------------------
// Prototypes
// void Init_Steppers();
void disable_stepper1();
void disable_stepper2();
void step_stepper1();
void step_stepper2();
void rotate_stepper1(unsigned long steps, unsigned char direction, unsigned long frequency, unsigned char mode);
void rotate_stepper2(unsigned long steps, unsigned char direction, unsigned long frequency, unsigned char mode);
//--------------------------------------------------------------------------------------------------------------
// Timer1 Interrupt routine for stepper 1
void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void){

	if(stepper_enable1) step_stepper1();
	IFS0bits.T1IF = 0;       /* clear interrupt flag     */
	return;
}
//--------------------------------------------------------------------------------------------------------------
// Timer2 Interrupt routine for stepper 2
void __attribute__((interrupt, no_auto_psv)) _T2Interrupt(void){

	step_stepper2();
	IFS0bits.T2IF = 0;       /* clear interrupt flag     */
	return;
}
//--------------------------------------------------------------------------------------------------------------
// Init Timers
void Init_Steppers(){

	STEPPERS_TRIS	&= 0xFE00; 	// configure PORTB for output (STEPPERS)
	ADPCFG			 = 0xFFFF;	// configure PORTB for digital output
	MAIN_SWITCH		 = 0;		// turn on the main switch mosfet

/* Enable Timer1 Interrupt and Priority to "5" */
    ConfigIntTimer1(T1_INT_PRIOR_6 & T1_INT_ON);

    OpenTimer1(T1_ON & T1_GATE_OFF & T1_PS_1_8 & 
			 	T1_SOURCE_INT, 0xFFFF);

/* Enable Timer2 Interrupt and Priority to "5" */
    ConfigIntTimer2(T2_INT_PRIOR_6 & T2_INT_ON);

    OpenTimer2(T2_ON & T2_GATE_OFF & T2_PS_1_8 
				 & T2_SOURCE_INT, 0xFFFF);

}
//--------------------------------------------------------------------------------------------------------------
// Stepper Control Routines
void rotate_stepper1(unsigned long steps, unsigned char direction, unsigned long frequency, unsigned char mode){
	
	if(mode){	// Full Stepper Mode
		if(direction){	// ClockWise Direction in Full Stepper Mode
			while(steps > 0){
				if(pos_stepper1 > 3) pos_stepper1 = 0;
				STEPPERS_PORT = (STEPPERS_PORT|0x0F)& step_full1[pos_stepper1++];
				__delay32(frequency);
				steps--;
			}
		}else{			// CounterClockWise Direction in Full Stepper Mode
			while(steps > 0){
				if(pos_stepper1 < 0) pos_stepper1 = 3;
				STEPPERS_PORT = (STEPPERS_PORT|0x0F)& step_full1[pos_stepper1--];
				__delay32(frequency);
				steps--;
			}
		}
	}else{		// Half Stepper Mode
		if(direction){	// ClockWise Direction in Half Stepper Mode
			while(steps > 0){
				if(pos_stepper1 > 7) pos_stepper1 = 0;
				STEPPERS_PORT = (STEPPERS_PORT|0x0F)& step_half1[pos_stepper1++];
				__delay32(frequency);
				steps--;
			}
		}else{			// CounterClockWise Direction in Half Stepper Mode
			while(steps > 0){
				if(pos_stepper1 < 0) pos_stepper1 = 7;
				STEPPERS_PORT = (STEPPERS_PORT|0x0F)& step_half1[pos_stepper1--];
				__delay32(frequency);
				steps--;
			}
		}
	}		
}

void rotate_stepper2(unsigned long steps, unsigned char direction, unsigned long frequency, unsigned char mode){
	if(mode){	// Full Stepper Mode
		if(direction){	// ClockWise Direction in Full Stepper Mode
			while(steps > 0){
				if(pos_stepper2 > 3) pos_stepper2 = 0;
				STEPPERS_PORT = (STEPPERS_PORT|0xF0)& step_full2[pos_stepper2++];
				__delay32(frequency);
				steps--;
			}
		}else{			// CounterClockWise Direction in Full Stepper Mode
			while(steps > 0){
				if(pos_stepper2 < 0) pos_stepper2 = 3;
				STEPPERS_PORT = (STEPPERS_PORT|0xF0)& step_full2[pos_stepper2--];
				__delay32(frequency);
				steps--;
			}
		}
	}else{		// Half Stepper Mode
		if(direction){	// ClockWise Direction in Half Stepper Mode
			while(steps > 0){
				if(pos_stepper2 > 7) pos_stepper2 = 0;
				STEPPERS_PORT = (STEPPERS_PORT|0xF0)& step_half2[pos_stepper2++];
				__delay32(frequency);
				steps--;
			}
		}else{			// CounterClockWise Direction in Half Stepper Mode
			while(steps > 0){
				if(pos_stepper2 < 0) pos_stepper2 = 7;
				STEPPERS_PORT = (STEPPERS_PORT|0xF0)& step_half2[pos_stepper2--];
				__delay32(frequency);
				steps--;
			}
		}
	}
}
//--------------------------------------------------------------------------------------------------------------
// Functions for use with interrupt timers
void step_stepper1(){
	
	unsigned char temp = 0;

	if(mode_step1){	// Full Stepper Mode
		if(direction1){	// ClockWise Direction in Full Stepper Mode
			if(pos_stepper1 > 3) pos_stepper1 = 0;
			temp = (STEPPERS_PORT|0x0F) & step_full1[pos_stepper1++];
			STEPPERS_PORT = temp;
		}else{			// CounterClockWise Direction in Full Stepper Mode
			if(pos_stepper1 < 0) pos_stepper1 = 3;
			STEPPERS_PORT = (STEPPERS_PORT|0x0F) & step_full1[pos_stepper1--];
		}
	}else{		// Half Stepper Mode
		if(direction1){	// ClockWise Direction in Half Stepper Mode
			if(pos_stepper1 > 7) pos_stepper1 = 0;
			STEPPERS_PORT = (STEPPERS_PORT|0x0F)& step_half1[pos_stepper1++];
		}else{			// CounterClockWise Direction in Half Stepper Mode
			if(pos_stepper1 < 0) pos_stepper1 = 7;
			STEPPERS_PORT = (STEPPERS_PORT|0x0F)& step_half1[pos_stepper1--];
		}
	}		
}

void step_stepper2(){
	if(mode_step2){	// Full Stepper Mode
		if(direction2){	// ClockWise Direction in Full Stepper Mode
			if(pos_stepper2 > 3) pos_stepper2 = 0;
			STEPPERS_PORT = (STEPPERS_PORT|0xF0)& step_full2[pos_stepper2++];
		}else{			// CounterClockWise Direction in Full Stepper Mode
			if(pos_stepper2 < 0) pos_stepper2 = 3;
			STEPPERS_PORT = (STEPPERS_PORT|0xF0)& step_full2[pos_stepper2--];
		}
	}else{		// Half Stepper Mode
		if(direction2){	// ClockWise Direction in Half Stepper Mode
			if(pos_stepper2 > 7) pos_stepper2 = 0;
			STEPPERS_PORT = (STEPPERS_PORT|0xF0)& step_half2[pos_stepper2++];
		}else{			// CounterClockWise Direction in Half Stepper Mode
			if(pos_stepper2 < 0) pos_stepper2 = 7;
			STEPPERS_PORT = (STEPPERS_PORT|0xF0)& step_half2[pos_stepper2--];
		}
	}		
}
//-------------------------------------------------------------------------------------
// Disable functions (turn-off motors)
void disable_stepper1(){
	MAIN_SWITCH		 = 1;		//disables main switch
	STEPPERS_PORT	&= 0xF0;
}
void disable_stepper2(){
	MAIN_SWITCH		 = 1;		//disables main switch
	STEPPERS_PORT	&= 0x0F;
}

