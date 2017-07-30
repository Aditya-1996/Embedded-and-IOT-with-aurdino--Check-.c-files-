/*
 * main.c
 *
 *  Created on: 16-Apr-2017
 *      Author: Aditya
 */
//#include<avr/io.h>


int main()
{

	 /*//setup
	//Load UBRRH - upper 8 bits
	UBRR0H =(BPS>>8);

	//Load UBRRH - lower 8 bits
	UBRR0L=(BPS);

	//Enable3
	UCSR0B|=(1<<TXEN0)|(1<<RXEN0);
	*/

	uart_init();
	while(1)
	{
		if(uart_recieve()== 'O')
		{
			uart_send('K');
			uart_send('I');
		}

		/* while((UCSR0A & (1<<RXC0))==0);
		//UDR0='O';  //when UDR is set, it's high

		if(UDR0=='O')
		{
			while((UCSR0A & (1<<UDRE0))==0);
			UDR0='K';
		}
		//TXC0-6
		//while((UCSR0A&(1<<TXC0))==0); *//*Transmission is still going on*///can also just put a semicolon
		//UCSR0A|=(1<<TXC0);*/
	}
}


