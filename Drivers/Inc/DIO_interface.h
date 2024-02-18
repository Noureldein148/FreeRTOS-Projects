#include"STD_TYPES_H_.h"
#ifndef DIO_INTERFACE_H_INCLUDED
#define DIO_INTERFACE_H_INCLUDED

#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW  0


#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7


void DIO_SetPinDirection(u8 PORT , u8 pin , u8 direction);
void DIO_SetPinValue    (u8 PORT , u8 pin , u8 value);
u8 DIO_GetPinValue(u8 PORT , u8 pin);





#endif // DIO_INTERFACE_H_INCLUDED
