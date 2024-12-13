/************************************************************************/
/*      * DIO.c										**********************
* Created: 2023-07-12 6:59:50 PM					*********************
*  Author: Abdelrahman Ellithy								            */
/************************************************************************/
#include "../../LIB/BIT_OPERATIONS.h"
#include "Types.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"

void DIO_PIN_init( u8 portname ,u8 pinnumber , u8 drirection ){
	switch (portname)
	{
		case  DIO_PORTA :
		if (drirection==DIO_PIN_OUTPUT)
		{
			SET_BIT(DDRA,pinnumber);
		}
		else if (drirection==DIO_PIN_INPUT)
		{
			CLEAR_BIT(DDRA,pinnumber);
		}
		break;
		
		case DIO_PORTB :
		if (drirection==DIO_PIN_OUTPUT)
		{
			SET_BIT(DDRB,pinnumber);
		}
		else if (drirection==DIO_PIN_INPUT)
		{
			CLEAR_BIT(DDRB,pinnumber);
		}
		break;
		
		case DIO_PORTC :
		if (drirection==DIO_PIN_OUTPUT)
		{
			SET_BIT(DDRC,pinnumber);
		}
		else if (drirection==DIO_PIN_INPUT)
		{
			CLEAR_BIT(DDRC,pinnumber);
		}
		break;
		
		
		case DIO_PORTD :
		if (drirection==DIO_PIN_OUTPUT)
		{
			SET_BIT(DDRD,pinnumber);
		}
		else if (drirection==DIO_PIN_INPUT)
		{
			CLEAR_BIT(DDRD,pinnumber);
		}
		break;
	}
	
}
void DIO_PORT_init( u8 portname , u8 drirection ){
	switch (portname)
	{
		case  DIO_PORTA :
		if (drirection==DIO_PIN_OUTPUT)
		{
			SET_REG(DDRA);
		}
		else if (drirection==DIO_PIN_INPUT)
		{
			CLEAR_REG(DDRA);
		}
		break;
		
		case DIO_PORTB :
		if (drirection==DIO_PIN_OUTPUT)
		{
			SET_REG(DDRB);
		}
		else if (drirection==DIO_PIN_INPUT)
		{
			CLEAR_REG(DDRB);
		}
		break;
		
		case DIO_PORTC :
		if (drirection==DIO_PIN_OUTPUT)
		{
			SET_REG(DDRC);
		}
		else if (drirection==DIO_PIN_INPUT)
		{
			CLEAR_REG(DDRC);
		}
		break;
		
		
		case DIO_PORTD :
		if (drirection==DIO_PIN_OUTPUT)
		{
			SET_REG(DDRD);
		}
		else if (drirection==DIO_PIN_INPUT)
		{
			CLEAR_REG(DDRD);
		}
		break;
	}
	
}
void DIO_PORT_bits_init( u8 portname  , u8 bits ){
	switch (portname)
	{
		case DIO_PORTA :
		WRITE_REG(DDRA,bits);
		break;
		case DIO_PORTB :
		WRITE_REG(DDRB,bits);
		break;
		case DIO_PORTC :
		WRITE_REG(DDRC,bits);
		break;
		case DIO_PORTD :
		WRITE_REG(DDRD,bits);
		break;
	}
}

void DIO_PIN_write( u8 portname ,u8 pinnumber , u8 value ){
	
	switch (portname)
	{
		case DIO_PORTA :
		if (value==DIO_PIN_HIGH)
		{
			SET_BIT(PORTA,pinnumber);
			
		}
		else if (value==DIO_PIN_LOW)
		{
			CLEAR_BIT(PORTA,pinnumber);
		}
		break;
		
		case DIO_PORTB :
		if (value==DIO_PIN_HIGH)
		{
			SET_BIT(PORTB,pinnumber);
		}
		else if (value==DIO_PIN_LOW)
		{
			CLEAR_BIT(PORTB,pinnumber);
		}
		break;
		
		case DIO_PORTC :
		if (value==DIO_PIN_HIGH)
		{
			SET_BIT(PORTC,pinnumber);
		}
		else if (value==DIO_PIN_LOW)
		{
			CLEAR_BIT(PORTC,pinnumber);
		}
		break;
		
		
		case DIO_PORTD :
		if (value==DIO_PIN_HIGH)
		{
			SET_BIT(PORTD,pinnumber);
		}
		else if (value==DIO_PIN_LOW)
		{
			CLEAR_BIT(PORTD,pinnumber);
		}
		break;
	}
	
}
void DIO_PORT_write( u8 portname , u8 value ){
	
	switch (portname)
	{
		case DIO_PORTA :		
			WRITE_REG(PORTA,value);		
			break;	
		case DIO_PORTB :		
			WRITE_REG(PORTB,value);		
			break;		
		case DIO_PORTC :
			WRITE_REG(PORTC,value);
			break;
		case DIO_PORTD :
			WRITE_REG(PORTD,value);
			break;
	}
	
}
void DIO_PORT_write_bits( u8 portname , u8 bits ){
	switch (portname)
	{
		case DIO_PORTA :
			CLEAR_bits(PORTA,bits);
			Set_bits(PORTA,bits);
		break;
		case DIO_PORTB :
			CLEAR_bits(PORTB,bits);
			Set_bits(PORTB,bits);
		break;
		case DIO_PORTC :
			CLEAR_bits(PORTC,bits);
			Set_bits(PORTC,bits);
		break;
		case DIO_PORTD :
			CLEAR_bits(PORTD,bits);
			Set_bits(PORTD,bits);
		break;
	}
}
void DIO_PIN_read( u8 portname ,u8 pinnumber , u8 * value){

	switch (portname){
		case DIO_PORTA :
		*value = (PINA&(1<<pinnumber) );
		break;
		
		case DIO_PORTB :
		*value = GET_BIT(PINB, pinnumber);
		break;
		
		case DIO_PORTC :
		*value = GET_BIT(PINC, pinnumber);
		break;
		
		case DIO_PORTD :
		*value = GET_BIT(PIND, pinnumber);
		break;
	}
}
void DIO_PORT_read( u8 portname , u8 * value){

	switch (portname){
		case DIO_PORTA :
			 GET_REG(PINA,*value);
		break;
		
		case DIO_PORTB :
			GET_REG(PINB,*value);
		break;
		
		case DIO_PORTC :
			GET_REG(PINC,*value);
		break;
		
		case DIO_PORTD :
			GET_REG(PIND,*value);
		break;
	}

}

void DIO_PIN_toggle( u8 portname ,u8 pinnumber ){
	switch (portname)
	{
		case DIO_PORTA :TOGGLE_BIT(PORTA,pinnumber); break;
		case DIO_PORTB :TOGGLE_BIT(PORTB,pinnumber); break;
		case DIO_PORTC :TOGGLE_BIT(PORTC,pinnumber); break;
		case DIO_PORTD :TOGGLE_BIT(PORTD,pinnumber); break;
	}
}
void DIO_PORT_toggle( u8 portname  ){
	switch (portname)
	{
		case DIO_PORTA :
		TOGGLE_REG(PORTA);
		break;
		
		case DIO_PORTB :
		TOGGLE_REG(PORTB);
		break;
		
		case DIO_PORTC :
		TOGGLE_REG(PORTC);
		break;
		
		case DIO_PORTD :
		TOGGLE_REG(PORTD);
		break;
	}
}
void DIO_voidWriteHighNibbles(u8 Copy_u8PORT,u8 Copy_u8value)
{

	
	if ( (Copy_u8PORT <= DIO_PORTD))
	{
		Copy_u8value = (Copy_u8value<<4) ;
		switch(Copy_u8PORT)
		{
			case DIO_PORTA :
			CLEAR_High_nipple(PORTA);                   // make sure the high bits = 0000
			PORTA|=Copy_u8value;			//Set only the high nibble of the port A by the given value
			break ;
			case DIO_PORTB:
			CLEAR_High_nipple(PORTB);                 //Set only the high nibble of the port B by the given value
			PORTB=Copy_u8value;
			break ;
			case DIO_PORTC :
			 CLEAR_High_nipple(PORTC);               //Set only the high nibble of the port C by the given value
			PORTC|=Copy_u8value;
			break ;
			case DIO_PORTD:
			CLEAR_High_nipple(PORTD);                 //Set only the high nibble of the port D by the given value
			PORTD|=Copy_u8value;
			break ;
			default: break ;

		}
	}
	
}
void DIO_voidWriteLowNibbles(u8 Copy_u8PORT,u8 Copy_u8value)
{
	

	if ( (Copy_u8PORT <= DIO_PORTD))
	{
		Copy_u8value&=0x0f;
		switch(Copy_u8PORT)
		{
			case DIO_PORTA :
			CLEAR_low_nipple(PORTA);                 //Set only the high nibble of the port A by the given value
			PORTA |= Copy_u8value;
			break ;
			case DIO_PORTB:
			CLEAR_low_nipple(PORTB);                 //Set only the high nibble of the port B by the given value
			PORTB |= Copy_u8value;
			break ;
			case DIO_PORTC :
			CLEAR_low_nipple(PORTC);                 //Set only the high nibble of the port C by the given value
			PORTC |= Copy_u8value;
			break ;
			case DIO_PORTD:
			CLEAR_low_nipple(PORTD);                 //Set only the high nibble of the port D by the given value
			PORTD |= Copy_u8value;
			break ;
			default: break ;

		}


	}

}
