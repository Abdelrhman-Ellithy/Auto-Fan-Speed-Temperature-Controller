/*
 * Fan Speed Controller.c
 *
 * Created: 2023-11-15 9:31:25 AM
 * Author : Abdelrahman Ellithy
 */ 
#define F_CPU 8000000UL
#include "LIB/Types.h"
#include "LIB/BIT_OPERATIONS.h"
#include "MCAL/PORT Driver/PORT_interface.h"
#include "MCAL/Timers/Timers_Interface.h"
#include "HAL/LCD Driver/CLCD_interface.h"
#include "HAL/LM35 Driver/LM35_Interface.h"
#include "util/delay.h"
#define frist 0xff
int main(void)
{
	u8 tempreture;
	u8 str_spaces[]="  ";
	u8 str_speed[]="SPEED";
	u8 str_fan[]="FAN:";
	u8 str_on[]="ON ";
	u8 str_off[]="OFF ";
	u8 str_tempis[]="TEMPRETURE: ";
	PORT_voidInit();
	ADC_VoidInit();
	CLCD_voidInit();
	u8 last_temp=frist;
	CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
	CLCD_voidSendString(str_tempis);
	CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_1);
	CLCD_voidSendString(str_fan);
	CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_9);
	CLCD_voidSendString(str_speed);
	Timer0_init();
	Timer0_Run();
	u8 rem;
	u8 oc_val=0xff,old_oc_val=0x00;
	while (1)
	{	

		LM35_VoidRead(&tempreture);
			if(last_temp!=tempreture)
			{
				if (tempreture<10||(last_temp>99 && tempreture<100))
				{
					CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_15);
					CLCD_voidSendString(str_spaces);
				}
				CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_14);
				CLCD_voidSendNumber(tempreture);
				if(tempreture<20)
				{
					oc_val=0x00;
					if (last_temp>19|| last_temp==frist )
					{
							CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_5);
							CLCD_voidSendString(str_off);
							CLCD_voidSendString(str_speed);
							CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_14);
							CLCD_voidSendData('%');
							CLCD_voidSendData('0');
							CLCD_voidSendData('0');
							CLCD_voidSendData(' ');
					}
					
				}
				else
				{
					if (last_temp<20|| last_temp==frist)
					{
						CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_5);
						CLCD_voidSendString(str_on);
						CLCD_voidSendString(str_speed);
						CLCD_voidSendData('%');
					}
					CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_14);
					rem=tempreture%10;
					if(tempreture>59){
						oc_val=255;
							CLCD_voidSendNumber(100);
					}
					
					else if(tempreture>49){
						oc_val=229 +(rem/2)*5;
							CLCD_voidSendNumber(90+rem);
							CLCD_voidSendData(' ');
					}
					else if(tempreture>=39){
						oc_val=191+(rem*2.55);
							CLCD_voidSendNumber(75+rem);
							CLCD_voidSendData(' ');
					}
					else if(tempreture>29){
						oc_val=178+(rem*2.55);
							CLCD_voidSendNumber(60+rem);
							CLCD_voidSendData(' ');
					}
					else if(tempreture>19){
						oc_val=127+(rem*2.55);
						
						CLCD_voidSendNumber(50+rem);
						CLCD_voidSendData(' ');
					}
				}
			}
		last_temp=tempreture;
		if(oc_val!=old_oc_val){
			Timer0_VoidOC0setload(oc_val);
			old_oc_val=oc_val;
		}
	}
}