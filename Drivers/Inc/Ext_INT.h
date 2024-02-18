/*

 * Ext_INT.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Nour
 */
#include"Ext_INT_Config.h"
#include "STD_TYPES_H_.h"
#ifndef EXT_INT_H_
#define EXT_INT_H_

void Ext_Int_Init(u8 n ,u8 m);

void __vector_1(void) __attribute__((signal));  // INT0
void __vector_2(void) __attribute__((signal));  // INT1
void __vector_3(void) __attribute__((signal));  // INT2

void callback_Ext_INT0(void(*ptf)(void));
void callback_Ext_INT1(void(*ptf)(void));
void callback_Ext_INT2(void(*ptf)(void));

#endif /* EXT_INT_H_ */
