/*
 * main.c
 *
 *  Created on: 30-Apr-2017
 *      Author: Aditya
 */

#include<avr/io.h>

#define left_sensor 0    //PC0
#define right_sensor 1	//PC1
#define left_motor 2	//PC2
#define left_motor1 3	//PC3
#define right_motor 4	//PC4
#define right_motor1 5	//PC5
#define left_input (PINC & (1<<left_sensor))
#define right_input (PINC & (1<<right_sensor))

int main()
{
	// setup part
	DDRC&=~(1<<left_sensor);
	DDRC&=~(1<<right_sensor);
	DDRC|=(1<<left_motor);
	DDRC|=(1<<left_motor1);
	DDRC|=(1<<right_motor);
	DDRC|=(1<<right_motor1);

	while(1)
	{
		if(left_input!=0 && right_input!=0)
		{
			//Go forward
			PORTC&=~(1<<left_motor);
			PORTC|=(1<<left_motor1);
			PORTC&=~(1<<right_motor);
			PORTC|=(1<<right_motor1);
		}
		else if(left_input==0 && right_input==0)
		{
			PORTC|=(1<<left_motor);
			PORTC&=~(1<<left_motor1);
			PORTC|=(1<<right_motor);
			PORTC&=~(1<<right_motor);

		}
		else if(left_sensor==0)
		{
			PORTC|=(1<<right_motor);
			PORTC|=(1<<right_motor1);
			PORTC|=(1<<left_motor1);
			PORTC&=~(1<<left_motor1);
		}
		else if(right_sensor==0)
		{
			PORTC|=(1<<left_motor);
			PORTC|=(1<<left_motor1);
			PORTC|=(1<<right_motor1);
			PORTC&=~(1<<right_motor1);
		}

	}

}






