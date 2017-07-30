/*
 * uart.h
 *
 *  Created on: 30-Apr-2017
 *      Author: Aditya
 */

#ifndef UART_H_
#define UART_H_
#define baudrate 9600
#define BPS ((F_CPU/(16UL*baudrate))-1)
#include<avr/io.h>

void uart_send(uint8_t senddata);	//sending
uint8_t uart_recieve(); //recieving
void uart_init();





#endif /* UART_H_ */
