/*
 * LCD_Config.h
 *
 *  Created on: Oct 22, 2023
 *      Author: admin
 */
#include"STD_TYPES_H_.h"
#include"BITMATH.h"
#include "DIO_interface.h"

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
// Control
#define LCD_CTRL_PORT 	DIO_PORTA

#define LCD_EN_PIN 		DIO_PIN2
#define LCD_RS_PIN		DIO_PIN3

//Data Pins
#define LCD_DATA_PORT 		DIO_PORTB

#define LCD_DATA_PIN_4   	DIO_PIN0
#define LCD_DATA_PIN_5	 	DIO_PIN1
#define LCD_DATA_PIN_6	 	DIO_PIN2
#define LCD_DATA_PIN_7	 	DIO_PIN4


#endif /* LCD_CONFIG_H_ */
