/*
 * Button.h
 *
 * Created: 2023-07-20 2:54:39 PM
 *  Author: Abdelrahman Ellithy
 */ 
#ifndef BUTTON_H_
#define BUTTON_H_


#define BTN_Pressed DIO_PIN_HIGH
#define BTN_NotPressed DIO_PIN_LOW


void Button_read( u8 portname ,u8 pinnumber , u8 * value);


#endif /* BUTTON_H_ */