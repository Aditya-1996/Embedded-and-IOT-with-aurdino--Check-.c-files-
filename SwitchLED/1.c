/*
 * 1.c
 *
 *  Created on: 14-Apr-2017
 *      Author: Aditya
 */

#include<avr/io.h>
int main()
{
		int flag=0;
		//input pin 36 - PC1
		DDRC &= ~(1<<1);
		//o/p pin - led pin37 - PC0
		DDRC|=(1<<0);
		PORTC |= (1<<1);
		while(1)
		{
			if((PINC & (1<<1)) == 0) //switch is pressed
			{
				//LED on
				if(flag==1)
					PORTC &= ~(1<<0);
				else
					PORTC |= (1<<0);
				flag ^=1;
			}
			/*else
			{
				//LED off switch not pressed
				PORTC &= ~(1<<0);

			}*/
		}
}




