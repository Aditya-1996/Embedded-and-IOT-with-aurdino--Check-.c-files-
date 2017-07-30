/*
 * PIR1.c
 *
 *  Created on: 16-Apr-2017
 *      Author: Aditya
 */



#include<avr/io.h>
int main()
{
	//setup part
	//PIN - 37 - LED o/p
	DDRC&=~(1<<1);
	while(1)
	{
		if((PINC&(1<<1))!=0)
		{
			//Set LED on
			PORTC|=(1<<0);
		}
		else
		{
			//Set LED off
			PORTC&=~(1<<0);
		}
	}
}
