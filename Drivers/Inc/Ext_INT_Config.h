/*
 * Ext_INT_Config.h

 *
 *  Created on: Oct 23, 2023
 *      Author: Nour
 */
#include"Ext_INT_private.h"
#ifndef EXT_INT_CONFIG_H_
#define EXT_INT_CONFIG_H_

/***************MCUR******************/
#define MCUCR_ISC00  0
#define MCUCR_ISC01  1
#define MCUCR_ISC10  2
#define MCUCR_ISC11  3
/***************MCUSR******************/
#define MCUSRR_ISC2  6
/***************GICR******************/
#define GICR_INT1  7
#define GICR_INT0  6
#define GICR_INT2  5
/***************GIFR******************/
#define GIFR_INTF1  7
#define GIFR_INTF0  6
#define GIFR_INTF2  5

#define Ext_INT0 0
#define Ext_INT1 1
#define Ext_INT2 2

#define Falling_Edge 0
#define Rising_Edge	 1



#endif /* EXT_INT_CONFIG_H_ */
