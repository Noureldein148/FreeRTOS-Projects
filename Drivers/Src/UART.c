/*
 * UART.c

 *
 *  Created on: Oct 29, 2023
 *      Author: Nour
 */
#include"UART_interface.h"
void UART_Init(void)
{
	UCSRC UCSRC_locdata;
	UCSRC_locdata.UMSEL =0b0;  //Asynchoruns

	/**************************************************/
	//Character size = 8  (size of data)
	UCSRC_locdata.UCSZ= 0b11;
	UCSRB_REG->UCSZ2= 0b0;

	/*************************************************/
	UCSRC_locdata.UPM = 0b11;	//Enable Odd parity

	/*************************************************/
	UCSRC_locdata.USBS = 0;  	// Stop bit is 1 bit
	/*************************************************/
	UBRRL_REG =BAUDRATE_96000 ; 			// Baud Rate = 9600
	/*************************************************/
	UCSRC_REG = *((u8*)&UCSRC_locdata);
	/*************************************************/

	UCSRB_REG->RXEN = 0b1;		// Recieve enable
	UCSRB_REG->TXEN = 0b1;      // Transmit enable

}

void UART_VoidSendChar(u8 data)
{
	while(UCSRA_REG->UDRE == 0);  // is the buffer ready
	UDR_REG = data;
}
u8 UART_U8ReceiveChar(void)
{
	u8 data;
	while(UCSRA_REG->UDRE == 0);  // is the buffer ready
	data = UDR_REG ;
	return data;
}
void UART_VoidSendString(u8* PO_U8_Data)
{
	while(*PO_U8_Data != '\0' )
	{
		UART_VoidSendChar(*PO_U8_Data);
		PO_U8_Data++;
	}
}
//void UART_Int_EN(void)
