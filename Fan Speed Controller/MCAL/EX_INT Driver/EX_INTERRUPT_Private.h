/*
 * EX_INTERRUPT_Private.h
 *
 * Created: 2023-11-13 8:55:30 PM
 *  Author: lenovo
 */ 


#ifndef EX_INTERRUPT_PRIVATE_H_
#define EX_INTERRUPT_PRIVATE_H_

typedef enum{
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE,
}Edge_trriger;

#define INT1 7
#define INT0 6
#define INT2 5

#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define INTF1 7
#define INTF0 6
#define INTF2 5



#endif /* EX_INTERRUPT_PRIVATE_H_ */