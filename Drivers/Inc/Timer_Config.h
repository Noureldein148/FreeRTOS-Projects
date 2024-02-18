/*

 * Timer_Config.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Nour
 */
#include"Timer_private.h"
#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

#define TIMER0_NO_CLK	 0b000  //Timer Stopped
#define NO_PRESCALAR	 0b001
#define PRESCALAR_8		 0b010
#define PRESCALAR_64	 0b011
#define PRESCALAR_256	 0b100
#define PRESCALAR_1024	 0b101

#define TIMER0_PRESCALAR  PRESCALAR_64
/**************************************************/


#define NORMAL_MODE 0
#define CTC_MODE    1
#define PPWM_MODE   2
#define FPWM_MODE	3

#define TIMER_0_MODE FPWM_MODE

#endif /* TIMER_CONFIG_H_ */
