#ifndef __RTC_H
#define __RTC_H	    

#include "stm32f10x.h"
#include "user_data.h"

////ʱ��ṹ��
//typedef struct 
//{
//	vu8 hour;
//	vu8 min;
//	vu8 sec;			
//	//������������
//	vu16 w_year;
//	vu8 w_month;
//	vu8 w_date;
//	vu8 week;		
//  vu16 day_of_year;	
//}_calendar_obj;		


//typedef	union
//	{
//		vu8 all[10];
//		struct 
//		{
//			vu8 sec;				/* 0-59	*/
//			vu8 min;    		/* 0-59	*/
//			vu8 hour;      		/* 0-23	*/
//			vu8 day;       		/* 1-31	*/
//			vu8 week;  		/* 0-6, 0=Sunday	*/
//			vu8 mon;     		/* 0-11	*/
//			vu16 year;      		/* 0-99	*/
//			vu16 day_of_year; 	/* 0-365	*/
//			vu8 is_dst;        /* daylight saving time on / off */		
//				
//		}Clk;
//	}UN_Time;


extern UN_Time Rtc;					//�����ṹ��


void Disp_Time(u8 x, u8 y, u8 size);			//���ƶ�λ�ÿ�ʼ��ʾʱ��
void Disp_Week(u8 x, u8 y, u8 size, u8 lang);	//��ָ��λ����ʾ����
u8 RTC_Init(void);        						//��ʼ��RTC,����0,ʧ��;1,�ɹ�;
u8 Is_Leap_Year(u16 year);						//ƽ��,�����ж�
u8 RTC_Get(void);								//����ʱ��   
u8 RTC_Get_Week(u16 year, u8 month, u8 day);
u32 Rtc_Set(u16 syear, u8 smon, u8 sday, u8 hour, u8 min, u8 sec,u8 flag);	//����ʱ��	
//void RTC_Check_Initial(void);

#endif
