/*
 * uart.c
 *
 *  Created on: 30-Apr-2017
 *      Author: Aditya
 */

#include "uart.h"
void uart_send(uint8_t senddata)
{
	while((UCSR0A & (1<<UDRE0)) == 0);
	UDR0=senddata;
}

uint8_t uart_recieve()
{
	while((UCSR0A& (1<<RXC0))==0);
	return UDR0;
}

void uart_init()
{
	//Load UBRRH - upper 8 bits
	UBRR0H =(BPS>>8);

	//Load UBRRH - lower 8 bits
	UBRR0L=(BPS);

	//Enable3
	UCSR0B|=(1<<TXEN0)|(1<<RXEN0);
}



