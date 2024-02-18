/*
 * UART_interface.h

 *
 *  Created on: Oct 29, 2023
 *      Author: NOUR
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
#include"UART_Config.h"
void UART_Init(void);
void UART_VoidSendChar(u8);
u8 UART_U8ReceiveChar(void);
void UART_VoidSendString(u8* PO_U8_Data);
#endif /* UART_INTERFACE_H_ */
