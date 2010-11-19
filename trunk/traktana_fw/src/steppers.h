#define STEPPERS_PORT LATB

// Protoypes
void rotate_stepper1(unsigned long steps, unsigned char direction,
						unsigned int frequency, unsigned char mode);
void rotate_stepper2(unsigned long steps, unsigned char direction,
						unsigned int frequency, unsigned char mode);
// Variables
unsigned char pos_stepper1 = 0;
unsigned char pos_stepper2 = 0;
const unsigned char step_full[4] = {0b0000001,
									0b0000010,
									0b0000100,
									0b0001000};

const unsigned char step_half[8] = {0b0000001,
									0b0000011,
									0b0000010,
									0b0000110,
									0b0000100,
									0b0001100,
									0b0001000,
									0b0001001};

