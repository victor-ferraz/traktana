#define STEPPERS_PORT LATB


void rotate_stepper1(unsigned int steps, unsigned char direction, unsigned int frequency, unsigned char mode);
void rotate_stepper2(unsigned int steps, unsigned char direction, unsigned int frequency, unsigned char mode);

unsigned char step_full[4] = {	0b0000001,
								0b0000010,
								0b0000100,
								0b0001000};

unsigned char step_half[8] = {	0b0000001,
								0b0000011,
								0b0000010,
								0b0000110,
								0b0000100,
								0b0001100,
								0b0001000,
								0b0001001};

