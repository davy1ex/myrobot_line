#include<avr/io.h>
#define leftSen PC0					//Connect Left Sensor At PC0
#define rightSen PC1				//Connect Right Sensor At PC1

int main(void)
{
	DDRC=0b00000000;						// make PC0,PC1 as input for both sensors 0b11111100
	DDRB=0b00000011;						// make Port  as output to connect motor pins 
	
	while(1)
	{
		PINC=0x03;					//initialize PC0 and PC1 0b00000011
		if(bit_is_clear(PINC,leftSen)){        // check if left sensor is OFF
			
			if(bit_is_clear(PINC,rightSen)) {    // check if right sensor is OFF
				PORTB=0b00000000;       // if both sensor zero
			}       // then stop the robot
			else{
				PORTB=0b00000001;                  // if right is ON then take left
			}
		}
		
		else                                  // check if left sensor in ON
		{
			if(bit_is_clear(PINC,rightSen)) {   // check if right sensor is OFF
				PORTB=0b00000010;      // it means left sensor is ON
			}      // so take right
			else{
				PORTB=0b00000011;            // if both sensor is ON
			}     // then keep moving the robot
		}
	}
}