/*
 * DIO_Interface.h
 *
 * Created: 2023-11-10 10:11:41 AM
 *  Author: Abdelrahman Ellithy
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
 
#include "Types.h"

 // Port Defines
#define  DIO_PORTA  0
#define  DIO_PORTB  1
#define  DIO_PORTC  2
#define  DIO_PORTD  3


 // PIN Defines
#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7


 // PIN Directions
#define DIO_PIN_OUTPUT		1
#define DIO_PIN_INPUT	    0

 // PIN Value Options
#define DIO_PIN_HIGH		1
#define DIO_PIN_LOW			0

 // PORT Directions
#define DIO_PORT_OUTPUT		0xFF
#define DIO_PORT_INPUT		0

#define DIO_PORT_HIGH      0xFF
#define DIO_PORT_LOW       0x00

#define DIO_PORT_OUT 0xff
/************************************************************************/
/* define  functions											    */
/************************************************************************/
void DIO_PIN_init( u8 portname ,u8 pinnumber , u8 drirection );
void DIO_PORT_init( u8 portname  , u8 drirection );
void DIO_PORT_bits_init( u8 portname  , u8 bits );

void DIO_PIN_write( u8 portname ,u8 pinnumber , u8 value );
void DIO_PORT_write( u8 portname  , u8 value );
void DIO_low_Nipple_write( u8 portname  , u8 bits );
void DIO_high_Nipple_write( u8 portname  , u8 bits );

void DIO_PIN_read( u8 portname ,u8 pinnumber , u8 * value);
void DIO_PORT_read( u8 portname  , u8 * value);

void DIO_PIN_toggle( u8 portname ,u8 pinnumber );
void DIO_PORT_toggle( u8 portname );

#endif /* DIO_INTERFACE_H_ */