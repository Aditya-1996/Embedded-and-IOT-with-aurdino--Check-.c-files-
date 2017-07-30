/*
 * main.c
 *
 *  Created on: 01-May-2017
 *      Author: Aditya
 */

#include "uart.h"
#define left_motor 2	//PC0
#define left_motor1 3	//PC1
#define right_motor 4	//PC2
#define right_motor1 5	//PC3
#include<util/delay.h>

int main()
{
	DDRC|=(1<<left_motor);
	DDRC|=(1<<left_motor1);
	DDRC|=(1<<right_motor);
	DDRC|=(1<<right_motor1);
	uart_init();


	while(1)
	{
		if(uart_recieve()== 'F')
		{
			PORTC|=(1<<left_motor);
			PORTC&=~(1<<left_motor1);
			PORTC&=~(1<<right_motor);
			PORTC|=(1<<right_motor1);
		}

		if(uart_recieve()== 'B')
		{
			PORTC&=~(1<<left_motor);
			PORTC|=(1<<left_motor1);
			PORTC|=(1<<right_motor);
			PORTC&=~(1<<right_motor1);
		}

		if(uart_recieve()== 'L')
				{
					PORTC|=(1<<left_motor);
					PORTC|=(1<<left_motor1);
					PORTC|=(1<<right_motor);
					PORTC&=~(1<<right_motor1);
					_delay_ms(3000);
					PORTC|=(1<<left_motor);
					PORTC|=(1<<left_motor1);
					PORTC|=(1<<right_motor);
					PORTC|=(1<<right_motor1);


				}
		if(uart_recieve()== 'R')
				{
					PORTC&=~(1<<left_motor);
					PORTC|=(1<<left_motor1);
					PORTC|=(1<<right_motor);
					PORTC|=(1<<right_motor1);
				}


	}
}


