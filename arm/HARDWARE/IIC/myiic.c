#include "product.h"
#include "myiic.h"
#include "delay.h"

extern u16 Test[50];
//��ʼ��IIC

U8_T Get_Mini_Type(void);


void IIC_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
#if (ARM_MINI || ARM_CM5)
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOD, ENABLE);//ʹ��GPIOBʱ��

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_SetBits(GPIOA, GPIO_Pin_8 | GPIO_Pin_15);	
#endif
	
#if ARM_TSTAT_WIFI
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//ʹ��GPIOBʱ��

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_SetBits(GPIOA, GPIO_Pin_2 | GPIO_Pin_3);	
#endif
}


//����IIC��ʼ�ź�
void IIC_Start(void)
{
	SDA_OUT();		//sda�����
	IIC_SDA = 1;	  	  
	IIC_SCL = 1;
	delay_us(8);
 	IIC_SDA = 0;	//START:when CLK is high,DATA change form high to low 
	delay_us(4);
	IIC_SCL = 0;	//ǯסI2C���ߣ�׼�����ͻ�������� 
}
	  
//����IICֹͣ�ź�
void IIC_Stop(void)
{
	SDA_OUT();		//sda�����
	IIC_SCL = 0;
	IIC_SDA = 0;	//STOP:when CLK is high DATA change form low to high
 	delay_us(4);
	IIC_SCL = 1; 
	IIC_SDA = 1;	//����I2C���߽����ź�
	delay_us(4);							   	
}

#if !(ARM_TSTAT_WIFI )	
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
u8 IIC_Wait_Ack(void)
{
	u8 i;
	IIC_SCL=1;
	delay_us(2);
	IIC_SCL=0;
	for (i=0; i<100; i++)
	{
		SDA_OUT();
		IIC_SDA = 1;
	//c=I2C_SDA;
		SDA_IN();
		if (READ_SDA == 0){
	// if data line is low, pulse the clock.
			delay_us(5);
		
		return 0;
		}		
	}
	IIC_SCL=0;
	return 1;
}

#else

// for TSTAT10 humidity
u8 IIC_Wait_Ack(void)
{
	u8 ucErrTime = 0;
	SDA_IN();		//SDA����Ϊ����    
	IIC_SDA = 1;
	delay_us(1);	   
	IIC_SCL = 1;
	delay_us(1);	 
	while(READ_SDA)
	{
		ucErrTime++;
		if(ucErrTime > 250)
		{
			IIC_Stop();
			return 1;
		}
	}
	IIC_SCL = 0;	//ʱ�����0 	   
	return 0; 
}

#endif

 

 

//����ACKӦ��
void IIC_Ack(void)
{
	IIC_SCL = 0;
	SDA_OUT();
	IIC_SDA = 0;
	delay_us(2);
	IIC_SCL = 1;
	delay_us(2);
	IIC_SCL = 0;
	
	IIC_SDA = 1;	// JMO
	delay_us(2);	// JMO
}

//������ACKӦ��		    
void IIC_NAck(void)
{
	IIC_SCL = 0;
	SDA_OUT();
	IIC_SDA = 1;
	delay_us(2);
	IIC_SCL = 1;
	delay_us(2);
	IIC_SCL = 0;
	
	IIC_SDA = 1;	// JMO
	delay_us(2);	// JMO
}
					 				     
//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��

void IIC_Send_Byte(u8 txd)
{                        
    u8 t;   
	  SDA_OUT(); 	    
    IIC_SCL = 0;		//����ʱ�ӿ�ʼ���ݴ���	
    for(t = 0; t < 8; t++)
    {	
			IIC_SDA = (txd & 0x80) >> 7;
			txd <<= 1; 	  
			delay_us(2);   //��TEA5767��������ʱ���Ǳ����
			IIC_SCL = 1;
			delay_us(2); 
			IIC_SCL = 0;	
			delay_us(2);
    }
		IIC_SDA = 0;
}
	    
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK   
u8 IIC_Read_Byte(unsigned char ack)
{
	unsigned char i, receive = 0;
	receive = 0;

	SDA_IN();			//SDA����Ϊ����

  for(i = 0; i < 8; i++)
	{
		IIC_SCL = 0; 
		delay_us(2);
		IIC_SCL = 1;
		receive <<= 1;
		if(READ_SDA)
			receive++;   
		delay_us(1); 
  }
						 
	if(!ack)
			IIC_NAck();//����nACK
	else
			IIC_Ack(); //����ACK
		   
    return receive;
}
