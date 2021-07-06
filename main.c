/*
 * main.c
 *
 * Created: 24-Jun-21 12:46:01 AM
 *  Author: dezy1ex
 */ 

#include <xc.h>
#include <avr/io.h>

#define leftSen PC2                //Connect Left Sensor At PA0
#define rightSen PC3               //Connect Right Sensor At PA1

int main(void)
{
	DDRC=0b0000000;                // make PA0,PA1 as input for both sensors 0x0b11111100
	DDRB=0b00011110;				//DEFINE PB1,PB2,PB3,PB4 AS OUTPUT LINES 
	int sensor=0;
	
	while(1)
	{
		sensor = PINC & 0b0000011; //STATEMENT TO STORE VALUE FROM PIN REGISTER TO VARIABLE
		if(sensor==0b0000011)     //CONDITIONAL STATEMENTS
		{PORTB=0b00001010;}
		else if (sensor==0b0000001)
		{PORTB=0b00000010;}
		else if(sensor==0b0000010)
		{PORTB=0b00001000;}
		else                       //CONDITION WHEN BOTH SENSORS ARE OFF
		{PORTB=0b00000000;}
	}
}