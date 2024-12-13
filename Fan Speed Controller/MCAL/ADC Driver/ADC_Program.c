/*
 * ADC_Program.c
 *
 * Created: 2023-11-15 6:46:20 AM
 *  Author: lenovo
 */ 
#include "Types.h"
#include "BIT_OPERATIONS.h"
#include "ADC_Interface.h"
#include "ADC_Config.h"
#include "ADC_Private.h"

void ADC_VoidInit(void){
	
	/*  select adjustment */
	#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
		CLEAR_BIT(ADMUX,ADLAR);
	#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
		SET_BIT(ADMUX,ADLAR);
	#endif	
	/*  select voltage refrance */
	#if ADC_VREF == AVCC
		SET_BIT(ADMUX, REFS0);
		CLEAR_BIT(ADMUX, REFS1);
	#elif ADC_VREF == AREF
		CLEAR_BIT(ADMUX, REFS0);
		CLEAR_BIT(ADMUX, REFS1);
	#elif ADC_VREF == INTERNAL_2_56
		SET_BIT(ADMUX, REFS0);
		SET_BIT(ADMUX, REFS1);
	#endif
	
	
	/* select channel */
	ADMUX&=ADC_CH_MASK;
	ADMUX|= ADC_CHANNEL;
	
	
	/*select source */
	#if	  ADC_TRIGGERING_SOURCE == ADC_SINGLE_CONVERSION
		CLEAR_BIT(ADCSRA,ADATE);
	#endif
	
	
	/*  Set Prescaler Value  */
	ADCSRA &= ADC_PRE_MASK ;
	ADCSRA |= ADC_PRESCALLER ;
	/*                      */
	
	/* select ADC status Enable or Disable */
	#if ADC_STATUS == ADC_ENABLE
		SET_BIT(ADCSRA, ADEN);
	#elif ADC_STATUS == ADC_DATA_RE
		CLEAR_BIT(ADCSRA, ADEN);
	#endif
	
	/* select ADC Interrupt status Enable or Disable */
	#if INT_STATUS== INT_ENABLE
		SET_BIT(ADCSRA, ADIE);
	#elif INT_STATUS== INT_DISABLE
		CLEAR_BIT(ADCSRA, ADIE);
	#endif
	
}
/*void ADC_INT_ENABLE(void); */
/*void ADC_INT_DISABLE(void); */
void ADC_Get_Read(u16 *value ){
	SET_BIT(ADCSRA,ADSC);
	while(1==GET_BIT(ADCSRA,ADSC));
	*value=(ADCL|ADCH<<8);
}
void ADC_VoidSet_channel(u8 channel){
	ADMUX&=ADC_CH_MASK;
	ADMUX|= channel;
}
void ADC_VoidSet_prescaler(u8 prescaler){
	ADCSRA &= ADC_PRE_MASK ;
	ADCSRA |= prescaler ;
}