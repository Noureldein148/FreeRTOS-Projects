/*
' * UART_Private.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Nour
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_
#include"STD_TYPES_H_.h"


#define UBRRH_REG	*((volatile u8*)0X40)
#define UBRRL_REG	*((volatile u8*)0X29)
#define UCSRC_REG   *((volatile u8*)0X40)
#define UDR_REG     *((volatile u8*)0X2C)

typedef struct
{
	u8 MPCM: 1 ;
	u8 U2X : 1 ;
	u8 PE  : 1 ;
	u8 DOR : 1 ;
	u8 FE  : 1 ;
	u8 UDRE: 1 ;
	u8 TXC : 1 ;
	u8 RXC : 1 ;
}UCSRA;
#define UCSRA_REG ((volatile UCSRA*)0X2B)

typedef struct
{
	u8 TXB8  : 1 ;
	u8 RXB8  : 1 ;
	u8 UCSZ2 : 1 ;
	u8 TXEN  : 1 ;
	u8 RXEN  : 1 ;
	u8 UDRIE : 1 ;
	u8 TXCIE : 1 ;
	u8 RXCIE : 1 ;
}UCSRB;
#define UCSRB_REG ((volatile UCSRB*)0X2A)

typedef struct
{
	u8 UCPOL : 1 ;
	u8 UCSZ  : 2 ;
	u8 USBS  : 1 ;
	u8 UPM   : 2 ;
	u8 UMSEL : 1 ;
	u8 USREL : 1 ;
}UCSRC;
#define UCSRC_REG *((volatile u8*)0X40)



#endif /* UART_PRIVATE_H_ */
