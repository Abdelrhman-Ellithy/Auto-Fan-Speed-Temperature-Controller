/*
 * Button.c
 *
 * Created: 2023-07-20 2:54:56 PM
 *  Author: Abdelrahman Ellithy
 */ 
#include "../../LIB/Types.h"
#include "../../MCAL/DIO Driver/DIO_Interface.h"
#include "Button_interface.h"
void Button_read( u8 portname ,u8 pinnumber , u8 * val){
	DIO_PIN_read(portname , pinnumber , val);
	if(*val==BTN_Pressed){
		while(*val==BTN_Pressed){
			DIO_PIN_read(portname , pinnumber , val);
		}
	}
	else{
		*val=BTN_NotPressed;
	}
}