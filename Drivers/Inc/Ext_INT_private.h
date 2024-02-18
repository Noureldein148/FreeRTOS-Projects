/*
 * Ext_INT_private.h

 *
 *  Created on: Oct 23, 2023
 *      Author: Nour
 */


#ifndef EXT_INT_PRIVATE_H_
#define EXT_INT_PRIVATE_H_


/***************MCUCR******************/
#define MCUCR_REG 	*((volatile u8*)0X55)
/***************MCUSR******************/
#define MCUCSR_REG 	*((volatile u8*)0X54)
/***************GICR******************/
#define GICR_REG 	*((volatile u8*)0X5B)
/***************GIFR******************/
#define GIFR_REG 	*((volatile u8*)0X5A)





#endif /* EXT_INT_PRIVATE_H_ */
