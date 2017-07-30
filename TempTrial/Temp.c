/*
 * Temp.c
 *
 *  Created on: 16-Apr-2017
 *      Author: Aditya
 */
#include<avr/io.h>
#include<util/delay.h>
#include<stdio.h>  

int main()
{
	DDRC&=~(1<<1);
	PINC|=(1<<1);
	printf("hey!!");
}
