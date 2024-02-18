#include "STD_TYPES_H_.h"
#include"BITMATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_CONFIG.h"


void DIO_SetPinDirection(u8 port , u8 pin , u8 direction)
{
    if(direction == DIO_PIN_HIGH)
    {
        switch(port)
        {
        case DIO_PORTA: SetBit(DDRA,pin ); break;
        case DIO_PORTB: SetBit(DDRB,pin);  break;
        case DIO_PORTC: SetBit(DDRC,pin);  break;
        case DIO_PORTD: SetBit(DDRD,pin);  break;

        }
    }
    else if(direction == DIO_PIN_LOW)
    {
        switch(port)
        {
            case DIO_PORTA: ClearBit(DDRA,pin);  break;
            case DIO_PORTB: ClearBit(DDRB,pin);  break;
            case DIO_PORTC: ClearBit(DDRC,pin);  break;
            case DIO_PORTD: ClearBit(DDRD,pin);  break;
        }
    }
}

// 5ALAS A5DNA KARAR ENHA OUTPUT BS HMTL3 OUTPUT EH
void DIO_SetPinValue    (u8 PORT , u8 pin , u8 value)
{
    if(value == DIO_PIN_HIGH)
    {
        switch(PORT)
        {
            case DIO_PORTA : SetBit(PORTA,pin) ; break;
            case DIO_PORTB : SetBit(PORTB,pin) ; break;
            case DIO_PORTC : SetBit(PORTC,pin) ; break;
            case DIO_PORTD : SetBit(PORTD,pin) ; break;
        }
    }
    else if(value == DIO_PIN_LOW)
    {
        switch(PORT)
        {
            case DIO_PORTA : ClearBit(PORTA,pin) ; break;
            case DIO_PORTB : ClearBit(PORTB,pin) ; break;
            case DIO_PORTC : ClearBit(PORTC,pin) ; break;
            case DIO_PORTD : ClearBit(PORTD,pin) ; break;
        }
    }

}
u8 DIO_GetPinValue(u8 PORT , u8 pin )
{
    u8 status=0;
    switch(PORT)
    {
        case DIO_PORTA: status = GetBit(PINA,pin); break;
        case DIO_PORTB: status = GetBit(PINB,pin); break;
        case DIO_PORTC: status = GetBit(PINC,pin); break;
        case DIO_PORTD: status = GetBit(PIND,pin); break;
    }
    return status;
}

void DIO_SetPortDirection(u8 port ,u8 direction)
{
    if(direction == DIO_PIN_HIGH)
    {
        switch(port)
        {
            case DIO_PORTA: DDRA = 0XFF; break;
            case DIO_PORTB: DDRB = 0XFF; break;
            case DIO_PORTC: DDRC = 0XFF; break;
            case DIO_PORTD: DDRD = 0XFF; break;
        }
    }
    else if(direction == DIO_PIN_LOW)
    {
        switch(port)
        {
            case DIO_PORTA: DDRA = 0X00; break;
            case DIO_PORTB: DDRB = 0X00; break;
            case DIO_PORTC: DDRC = 0X00; break;
            case DIO_PORTD: DDRD = 0X00; break;
        }
    }
}

void DIO_SetPortValue(u8 port , u8 direction)
{
    if( direction == DIO_PIN_HIGH)
    {
        switch(port)
        {
            case DIO_PORTA: PORTA = 0XFF; break;
            case DIO_PORTB: PORTB = 0XFF; break;
            case DIO_PORTC: PORTC = 0XFF; break;
            case DIO_PORTD: PORTD = 0XFF; break;
        }
    }
    else if( direction == DIO_PIN_LOW)
    {
        switch(port)
        {
            case DIO_PORTA: PORTA = 0X00; break;
            case DIO_PORTB: PORTB = 0X00; break;
            case DIO_PORTC: PORTC = 0X00; break;
            case DIO_PORTD: PORTD = 0X00; break;
        }
    }
}

void DIO_TogglePin(u8 port , u8 pin)
{
    switch(port)
    {
        case DIO_PORTA: ToggleBit(PORTA,pin); break;
        case DIO_PORTB: ToggleBit(PORTB,pin); break;
        case DIO_PORTC: ToggleBit(PORTC,pin); break;
        case DIO_PORTD: ToggleBit(PORTD,pin); break;
    }
}
