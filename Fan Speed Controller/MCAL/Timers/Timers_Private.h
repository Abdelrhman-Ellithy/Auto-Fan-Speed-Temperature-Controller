/*
 * Timers_Private.h
 *
 * Created: 2023-11-13 9:30:30 PM
 *  Author: Abdelrahman Ellithy
 */ 


#ifndef TIMERS_PRIVATE_H_
#define TIMERS_PRIVATE_H_

/************************************************************************/
/* timer 0 & macros									        */
/************************************************************************/
/* TCCR0 */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0
/************************************************************************/
/* Timer 0 PRESCALER											        */
/************************************************************************/
#define TM0_NO_CLK			 0x00
#define TM0_PRESCALER_1		 0x01
#define TM0_PRESCALER_8		 0x02
#define TM0_PRESCALER_64	 0x03
#define TM0_PRESCALER_256	 0x04
#define TM0_PRESCALER_1024	 0x05

/************************************************************************/
/*  OC0 Modes										        */
/************************************************************************/
#define OCO_DISCONNECTED			0
#define OCO_TOGGLE					1
#define OC0_NON_INVERTING			2
#define OC0_INVERTING				3
/************************************************************************/
/* Timer 0 MODES												        */
/************************************************************************/
#define TIMER0_NORMAL_MODE		  '0'
#define TIMER0_PHASE_CORRECT_MODE '1'
#define TIMER0_CTC_MODE           '2'
#define TIMER0_FASTPWM_MODE       '3'
/************************************************************************/
/* timer 1 & macros                                                     */
/************************************************************************/
/* TCCR1A */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0
/* TCCR1B */
#define ICNC1   7
#define ICES1   6
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

/************************************************************************/
/* timer 2  & macros                                                    */
/************************************************************************/
/* TCCR2 */
#define FOC2    7
#define WGM20   6
#define COM21   5
#define COM20   4
#define WGM21   3
#define CS22    2
#define CS21    1
#define CS20    0
/************************************************************************/
/* timer Special function registers  & macros                           */
/************************************************************************/

/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0

/* TIFR */
#define OCF2    7
#define TOV2    6
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2
#define OCF0    1
#define TOV0    0
/************************************************************************/
/*                timer macros										    */
/************************************************************************/
#define Timer0 0x01
#define Timer1 0x04
#define Timer2 0x40



#endif /* TIMERS_PRIVATE_H_ */