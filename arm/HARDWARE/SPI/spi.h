#ifndef __SPI_H
#define __SPI_H

#include "stm32f10x.h"

//�ⲿ��Ӧ���ݾ�����������޸�!
//Mini STM32ʹ�õ���PB12��ΪSD����CS��.
#define	SD_CS_BIG	PCout(5) //SD��Ƭѡ����					    	  
#define	SD_CS_SMALL	PDout(3)
#define	SD_CS_NEW_TINY	PDout(9)
#define SD_CS_TSTAT10   PGout(12)


void SPI1_Init(u8 type);							//��ʼ��SPI1��
void SPI1_SetSpeed(u8 SPI_BaudRatePrescaler);	//����SPI1�ٶ�   
u8 SPI1_ReadWriteByte(u8 TxData);				//SPI1���߶�дһ���ֽ�

void SPI2_Init(void);							//��ʼ��SPI1��
void SPI2_SetSpeed(u8 SPI_BaudRatePrescaler);	//����SPI1�ٶ�   
u8 SPI2_ReadWriteByte(u8 TxData);				//SPI1���߶�дһ���ֽ�
void SPI_Select_SD(void);
void SPI_Select_TOP(void);

void SPI3_Init(void);							//��ʼ��SPI1��
u8 SPI3_ReadWriteByte(u8 TxData);
void SPI3_SetSpeed(u8 SPI_BaudRatePrescaler);



#endif
