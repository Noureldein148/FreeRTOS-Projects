/*
 * LED.c
 *
 *  Created on: Feb 13, 2024
 *      Author: admin
 */
#include"BITMATH.h"
#include"DIO_private.h"
#include"DIO_interface.h"
#include"LED.h"
void LEDS_ALL_Init(void)
{
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN5 , DIO_PIN_HIGH);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN6 , DIO_PIN_HIGH);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN7 , DIO_PIN_HIGH);
}

void LEDS_ALL_TOGGLE(void)
{
	ToggleBit(PORTA , 5);
	ToggleBit(PORTA , 6);
	ToggleBit(PORTA , 7);
}

void LEDS_ALL_OFF(void)
{
	ClearBit(PORTA , 5);
	ClearBit(PORTA , 6);
	ClearBit(PORTA , 7);
}

void LED_RED_ON(void)
{
	DIO_SetPinValue(DIO_PORTA , DIO_PIN7 , DIO_PIN_HIGH);
}
void LED_GRN_ON(void)
{
	DIO_SetPinValue(DIO_PORTA , DIO_PIN6 , DIO_PIN_HIGH);
}
void LED_BLU_ON(void)
{
	DIO_SetPinValue(DIO_PORTA , DIO_PIN5 , DIO_PIN_HIGH);
}

void LED_RED_TOGGLE(void)
{
	ToggleBit(PORTA , 7);
}
void LED_GRN_TOGGLE(void)
{
	ToggleBit(PORTA , 6);
}
void LED_BLU_TOGGLE(void)
{
	ToggleBit(PORTA , 5);
}



