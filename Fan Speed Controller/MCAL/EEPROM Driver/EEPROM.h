/*
 * EEPROM.h
 *
 * Created: 2023-11-10 6:46:23 PM
 *  Author: Abdelrahman Ellithy
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "../../LIB/register.h"
#include "../../LIB/BIT_OPERATIONS.h"
#define EERE    0
#define EEWE    1
#define EEMWE   2
#define EERIE   3


void EEPROM_write( u16 address,  u8 data);

/**
 * @brief read byte from specific address
 * 
 * @param address to read from
 * @return u8 byte from address
 */
void EEPROM_read( u16 address, u8 *data);

/**
 * @brief Enable eeprom ready interrupt
 * 
 */
void EEPROM_intEnable(void);

/**
 * @brief disable eeprom ready interrupt
 * 
 */
void EEPROM_intDisable(void);

/**
 * @brief Set callback function for eeprom ready interrupt
 * 
 * @param localFptr pointer to function to run when eeprom ready interrupt fired
 */
void EEPROM_intSetCallback(void (*localFptr)(void));

#endif /* EEPROM_H_ */