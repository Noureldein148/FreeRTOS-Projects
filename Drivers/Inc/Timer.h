/*

 * Timer.h

 *
 *  Created on: Oct 27, 2023
 *      Author: Nour
 */
#include"Timer_Config.h"
#ifndef TIMER_H_
#define TIMER_H_
void Timer0_Init(void);
void Timer0_Stop(void);
void Timer0_Start(void);
void Timer0_Preload(u8 preload_val);
u8 Timer0_Val(void);
void __vector_11(void) __attribute__((signal));
void Callback_Timer0_OVF(void (*ptf)(void));

#endif /* TIMER_H_ */
