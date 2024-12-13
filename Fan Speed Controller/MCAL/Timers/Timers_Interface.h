/*
 * Timers_Interface.h
 *
 * Created: 2023-11-13 9:11:04 PM
 *  Author: lenovo
 */ 


#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_

void Timer0_init(void);
void Timer0_Run(void);
void Timer0_stop(void );
void Timer0_VoidOC0setload(u8 laod );
void Timer0_OV_InterruptEnable(void);
void Timer0_OV_InterruptDisable(void);
void Timer0_OC_InterruptEnable(void);
void Timer0_OC_InterruptDisable(void);

void TIMER0_COMP_SetCallBack(void(*LocalPtr)(void));
void TIMER0_OVFt_SetCallBack(void(*LocalPtr)(void));

#endif /* TIMERS_INTERFACE_H_ */