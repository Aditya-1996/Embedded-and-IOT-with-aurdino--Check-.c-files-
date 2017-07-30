/*
 * Trial1.c
 *
 *  Created on: 13-Apr-2017
 *      Author: Aditya
 */

#include<avr/io.h>
#include<util/delay.h>

int main()
{
	DDRC|=(1<<0);
	while(1)
	{
		PORTC|=(1<<0);
		_delay_ms(100);
		PORTC&=~(1<<0);
		_delay_ms(100);
	}
}
