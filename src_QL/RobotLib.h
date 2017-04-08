/******************** (C) COPYRIGHT 2010 STMicroelectronics ********************
* File Name          : RobotLib.h
* Author             : Team
* Version            : V1.0
* Date               : 9/26/2010
* Description        : Header for main.c module
********************************************************************************
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ROBOTLIB_H
#define __ROBOTLIB_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_lib.h"
//#include "lcd.h"
#include "spi_flash.h"

/***LCD5110*************************************************/
#include"stm32f10x_conf.h" 
#include"LCD5110_Driver.h"
#include"LCD5110_API.h"
/***LCD5110************************************************/

#include"rtc.h"		 
#include"key_selection.h"
/*************************************************************/
#include "usermain_c.h"
#include "usermain.h"


//*************************************************************************************
// define Name:          	EYE_0			
// define Description:	  	���۵ĺ궨��,���ڸ�����չ����
//*************************************************************************************
#define EYE_0		0

//*************************************************************************************
// define Name:          	EYE_1			
// define Description:	  	���۵ĺ궨��,���ڸ�����չ����
//*************************************************************************************
#define EYE_1		1


//*************************************************************************************
// define Name:          	UART_0			
// define Description:	  	���ڳ�ʼ������,�˿ں�
//*************************************************************************************
#define UART_0		0
 
//*************************************************************************************
// define Name:          	UART_1			
// define Description:	  	���ڳ�ʼ������,�˿ں�
//*************************************************************************************
#define UART_1		1

//*************************************************************************************
// define Name:          	PLL_X			
// define Description:	  	ϵͳʱ��Ƶ��
//*************************************************************************************
#define PLL_72		9
#define PLL_64		8
#define PLL_56		7
#define PLL_48		6
#define PLL_40		5
#define PLL_32		4
#define PLL_24		3
#define PLL_16		2

/**20110808����*****************************************/
void RCC_Configuration(void);
void GPIO_Configuration(void);
void NVIC_Configuration(void);
/**20110808����*****************************************/

/******************************************************************************************
* Function Name:      		MCLK_Config
* Function Discription:  	��CPU����ʱ��ʱ��Ƶ�ʣ��ɸ��ݹ��ĺ��ٶȵ�Ҫ�������á��������ṩ��8������Ƶ�ʣ��ȼ�Ϊ2-9����ӦCPUʱ��Ƶ�ʷֱ�Ϊ16M��24M����72M��
* params:  		   			MCLK_Clockȡֵ��Χ2-9��Ĭ��Ϊ9��
* return value: 			NULL
******************************************************************************************/
void MCLK_Config(char MCLK_Clock);

/******************************************************************************************
* Function Name:     		LCDControl
* Function Discription:    	����LCD��Ļ��ʾ
* params:  					cState����Χ0��1��0�����ص�LCD��ʾ��1������LCD��ʾ
* return value: 			NULL
******************************************************************************************/
//void LCDControl (char cState);

/******************************************************************************************
* Function Name:     		CLRLCD
* Function Discription:    	�����Ļ��ǰ����ʾ
* params:  					NULL
* return value: 			NULL
*****************************************************************************************/
//void CLRLCD(void);

/******************************************************************************************
* Function Name:     		Printf
* Function Discription:    	����Ļ�ϻ������֣��ڶ��ε��øú���ʱ������
* params:  					const char Ҫ���Ƶ��ַ���
* return value: 			
******************************************************************************************/
//int Printf(const char *fmt, ...);

/******************************************************************************************
* Function Name:     		cout
* Function Discription:    	����Ļ�ϻ������֣����ڶ��ε��øú���ʱ����������һֱд����Ļ�ײ��Ż����һ��
* params:  					const char Ҫ���Ƶ��ַ���
* return value: 			
******************************************************************************************/
//int cout(const char *fmt, ...);

/******************************************************************************************
* Function Name:     		DrawPixel
* Function Discription:    	����Ļ�������ϵĻ���һ�����صĵ�
* params:  					int X X������
							int Y Y������
							int color ���������ɫ
							�⺯�����Ѿ�����������ɫ�ĺ궨�壬��colorȡֵ��ΧΪWhite��Black��Grey��
							Blue��Blue2��Red��Magenta��Green��Cyan��Yellow��
* return value: 			NULL
******************************************************************************************/
//void DrawPixel (int x, int y, int color); 

/******************************************************************************************
* Function Name:     		DrawLine
* Function Discription:    	����Ļ�������ϵĻ���һ��ֱ��,��(X1,Y1)��(X2,Y2)
* params:  					int X1 �˵�1��X������
							int Y1 �˵�1��Y������
							int X2 �˵�2��X������
							int Y2 �˵�2��Y������
							int color �����ߵ���ɫ��ȡֵ��ΧΪWhite��Black��Grey��Blue��Blue2��Red��
							Magenta��Green��Cyan��Yellow
* return value: 			NULL
******************************************************************************************/
//void DrawLine(int x1,int y1,int x2,int y2,int color);

/******************************************************************************************
* Function Name:     		DrawRect
* Function Discription:    	����Ļ�������ϵĻ���һ�����Σ�XYΪ������С�ĵ�
* params:  					int X ������С�ĵ��X�����ꣻ
							int Y ������С�ĵ��Y�����ꣻ
							int width ���εĿ�ȣ�
							int height ���εĸ߶ȣ�
							int color ���ε���ɫ��ȡֵ��ΧΪWhite��Black��Grey��Blue��Blue2��Red��
							Magenta��Green��Cyan��Yellow
* return value: 			NULL
******************************************************************************************/
//void DrawRect(int x,int y,int width,int height,int color);





/******************************************************************************************
* Function Name:     		SetMoto
* Function Discription:    	����ĳһ��ͨ�������
* params:  					cChannel��ͨ���ţ��ֱ�Ϊ0��1��2��3��
							cSpeed���ٶ�ֵ����ΧΪ-100~100��
* return value: 			NULL
******************************************************************************************/
void SetMoto(char cChannel, signed char cSpeed);

/******************************************************************************************
* Function Name:     		SetAllMoto
* Function Discription:    	ͬʱ����4·�������
* params:  					iMaskΪ���룬����0x1111��ʾͬʱΪ4·��������ٶ�ֵ��
							0x1100��ʾֻΪͨ��0��ͨ��1�ĵ�������ٶ�ֵ��������ͨ��2��ͨ��3���ٶ�ֵ��
							cSpeed�ֱ�Ϊ4·ͨ��������ٶ�ֵ����ΧΪ-100~100��
* return value: 			NULL
******************************************************************************************/
void SetAllMoto(int iMask, signed char cSpeed0, signed char cSpeed1, signed char cSpeed2, signed char cSpeed3);
 
/******************************************************************************************
* Function Name:     		StopMoto
* Function Discription:    	ֹͣ��ѡͨ�����
* params:  					channel ��ֹͣ�ĵ����ͨ����
* return value: 			NULL
******************************************************************************************/
void StopMoto(char cChannel);

/******************************************************************************************
* Function Name:     		StopAllMoto
* Function Discription:    	4·���ȫ��ֹͣ����
* params:  					NULL
* return value: 			NULL
******************************************************************************************/
void StopAllMoto(void);
//#END REGION


//#REGION " ��ȡģ���/���ֿ�"

/******************************************************************************************
* Function Name:     		AI
* Function Discription:    	��ȡģ���ͨ�������롣
* params:  					cChannelΪͨ���ţ���Χ0-20��
* return value: 			����AD����ֵ����Χ-1023 ~ 1023����Ӧ-5V ~ +5V�ĵ�ѹֵ��
******************************************************************************************/
int AI(char cChannel);

/******************************************************************************************
* Function Name:     		DI
* Function Discription:    	��ȡ���ֿ�ͨ�������롣
* params:  					cChannelΪͨ���ţ���Χ0-7��
* return value: 			����0��1��
******************************************************************************************/
char DI(char cChannel);

//#END REGION


//#REGION "����"
/******************************************************************************************
* Function Name:     		EyeInMin
* Function Discription:    	��ȡ�������۴�������360�ȷ����϶�����С��ֵ
* params:  					NULL
* return value: 			���ض�����С��ֵ
******************************************************************************************/
int EyeInMin(void);

/******************************************************************************************
* Function Name:     		EyeChMin
* Function Discription:    	��ȡ�������۴�������360�ȷ�������С��ֵ���ڷ�����
* params:  					NULL
* return value: 			��ֵ��С��ͨ����ͨ���ţ���ΧΪ0-13
******************************************************************************************/
int EyeChMin(void);

/******************************************************************************************
* Function Name:     		EyeInMax
* Function Discription:    	��ȡ�������۴�������360�ȷ����϶�������ֵ��ͨ�������ĸ������ĸ���
							�����Խǿ������̽ͷ�Ķ���Խ��
* params:  					NULL
* return value: 			���ض�ֵ���ֵ
******************************************************************************************/
int EyeInMax(void);

/******************************************************************************************
* Function Name:     		EyeChMax
* Function Discription:    	��ȡ�������۴�������360�ȷ���������ֵ���ڷ�����
* params:  					NULL
* return value: 			���ض�ֵ����ͨ���ţ���ΧΪ0-13
******************************************************************************************/
int EyeChMax(void);

/******************************************************************************************
* Function Name:     		EyeInMinEx
* Function Discription:    	��ȡָ�����۴�������180�ȷ����϶�����С��ֵ
* params:  					��ѡ�ĸ��ۺţ���ΧΪEYE_0��EYE_1��
* return value: 			���ظø����ж�����С��ֵ
******************************************************************************************/
int EyeInMinEx(char cEYE);

/******************************************************************************************
* Function Name:     		EyeChMinEx
* Function Discription:    	��ȡָ�����۴�������180�ȷ�������С��ֵ���ڷ�����
* params:  					��ѡ�ĸ��ۺţ���ΧΪEYE_0��EYE_1
* return value: 			���ظø����ж�����С���ڷ���ı�ţ���Χ0 - 6��
******************************************************************************************/
int EyeChMinEx(char cEYE);
	
/******************************************************************************************
* Function Name:     		EyeInMaxEx
* Function Discription:    	��ȡָ�����۴�������180�ȷ����϶�������ֵ
* params:  					��ѡ�ĸ��ۺţ���ΧΪEYE_0��EYE_1
* return value: 			���ظø����ж�������ֵ
******************************************************************************************/
int EyeInMaxEx(char cEYE);

/******************************************************************************************
* Function Name:     		EyeChMaxEx
* Function Discription:    	��ȡָ�����۴�������180�ȷ���������ֵ���ڷ�����
* params:  					��ѡ�ĸ��ۺţ���ΧΪEYE_0��EYE_1
* return value: 			���ظø����ж���������ڷ���ı�ţ���Χ0 - 6
******************************************************************************************/
int EyeChMaxEx(char cEYE);

//#END REGION


//#REGION " DO ���������"
/******************************************************************************************
* Function Name:     		SetDO
* Function Discription:    	�趨�������
* params:  					cChannel ���������ͨ���ţ���ΧΪ0-7��
							cState �������״̬��1��������ߵ�ƽ��0��������͵�ƽ
* return value: 			NULL
******************************************************************************************/
void SetDO(char cChannel, char cState);

/******************************************************************************************
* Function Name:     		SetServo
* Function Discription:    	����������˿���Ϊ�ŷ���������źŶ˿ڣ����������ŷ����ת���ض��Ƕȣ�
							��ע�⣬��������������ŷ�������ŷ����������ӹ�����������
* params:  					cChannel ���������ͨ���ţ���ΧΪ0-7��
							ucAngle Ҫת���ĽǶȣ���ΧΪ0-180��
							cSpeed ת���Ľ��ٶȣ���ΧΪ0-100
* return value: 			NULL
******************************************************************************************/
//void SetServo(char cChannel,unsigned char ucAngle,char cSpeed);
void SetServo(char Channel_p,char Angle_p,char Speed_p);
void InitSV(void);
//#END REGION


//#REGION " I2C "
/******************************************************************************************
* Function Name:     		InitI2C
* Function Discription:    	I2C������ʽ��ʼ��
* params:  					uiI2CFreq�� I2C����Ƶ�ʣ�һ�㷶ΧΪ0-400000��Ĭ��ΪI2CFEC��
* return value: 			NULL
******************************************************************************************/
void InitI2C(unsigned int uiI2CFreq);

/******************************************************************************************
* Function Name:     		I2C_Save
* Function Discription:    	��I2C�����ϵ�ַΪEepromAddr�����������ַΪaddr�ĵ�Ԫ
д��һ���ֽڵ�����
* params:  					ucEepromAddr��I2C�����ϵ�����Ӳ����ַ����Χ��0~255
							ucAddr��I2C�����ϵ����������ַ����Χ:0~255
ucData��					Ҫ���͵����ݣ���λ����Χ:0~255
* return value: 			���д��ɹ�����1��д��ʧ�ܷ���0
******************************************************************************************/
u16 I2C_Save(unsigned char ucEepromAddr, unsigned char ucAddr, unsigned char ucData);
//char I2C_Save(unsigned char ucEepromAddr, unsigned char ucAddr, unsigned char ucData);

/******************************************************************************************
* Function Name:     		OpenLCD
* Function Discription:   	��ȡI2C�����ϵ�ַΪEepromAddr�����������ַΪaddr�ĵ�Ԫ������
* params:  					ucEepromAddr��I2C�����ϵ�����Ӳ����ַ����Χ��0~255
							ucAddr��I2C�����ϵ����������ַ����Χ:0~255
* return value: 			����8λ����
******************************************************************************************/
int I2C_Read(unsigned char ucEepromAddr, unsigned char ucAddr);
//unsigned char I2C_Read(unsigned char ucEepromAddr, unsigned char ucAddr);

/******************************************************************************************\
* Function Name:     	Sonar_Dis
* Function Discription:    ��ȡI2C�����ϳ���ģ��ľ������
* params:  			NULL
* return value: 			ָ������ٶȣ���Χ��0-255cm
\******************************************************************************************/
int Sonar_Dis(void);
//#END REGION


//#REGION " I2C�ӿڵ�����ָ����"

/******************************************************************************************
* Function Name:     		Compass_Degree
* Function Discription:   	��ȡI2C������ָ����ģ��ĽǶȶ���
* params:  					NULL
* return value: 			ָ������ٶȣ���Χ��0-359
******************************************************************************************/
int Compass_Degree(void);

//#END REGION


//#REGION " UART����"
/******************************************************************************************
* Function Name:     		UART_Set
* Function Discription:    	���ڳ�ʼ�����ú���
* params:  					����:unsigned int iPort
							����:��Ҫ��ʼ���Ĵ��ڱ��
							��Χ:UART_0,UART_1
							����:unsigned int uiBaud
							����:�������趨��Ĭ��9600
							��Χ:1200,4800,9600,38400,57600,115200
* return value: 			NULL
******************************************************************************************/
void UART_Set(char cPort,unsigned int uiBaud);

/******************************************************************************************
* Function Name:     		UART_Check
* Function Discription:    	�������ݲ�ѯ, ��⴮���Ƿ��յ�����
* params:  					cPort����Ҫ��ʼ���Ĵ��ڱ�ţ���Χ:UART_0,UART_1
* return value: 			��������յ����ݾͷ���1��û�յ����ݾͷ���0
******************************************************************************************/
char UART_Check(char cPort);

/******************************************************************************************
* Function Name:     		SCI_Send
* Function Discription:    	ʹ�ô��ڷ��͵����ֽ�����,�˺����Ƿ�������,���۴��ڷ���������,��ֱ�ӷ���
* params:  					cPort:���ڱ�ţ���Χ:UART_0,UART_1
							ucData:��Ҫ���͵����ݣ���Χ:0~255
* return value: 			NULL
******************************************************************************************/
void SCI_Send(char cPort, unsigned char ucData);
 
/******************************************************************************************
* Function Name:     		SCI_Receive
* Function Discription:     ���ڽ��պ���,�˺����Ƿ�������,���۴��ڽ���������,��ֱ�ӷ���
* params:  					cPort:���ڱ�ţ���Χ:UART_0,UART_1
* return value: 			���ڽ��յ���8λ����
******************************************************************************************/
unsigned char SCI_Receive(char cPort);

//#END REGION


//#REGION "��ť"
/******************************************************************************************
* Function Name:     		Get_Button
* Function Discription:    	�õ���ť��״̬����
* params:  					cKey����ť�ĺ��롣��������ֻ��1����ť����cKeyΪ0��
* return value: 			����0��1������1��ʾ�а������£�����0��ʾû�а������¡�
******************************************************************************************/
int Get_Button(char cKey);

//#END REGION


//#REGION "ϵͳʱ��"
/******************************************************************************************
* Function Name:     		resettime
* Function Discription:    	ϵͳʱ������Ϊ0
* params:  					NULL
* return value: 			NULL
******************************************************************************************/
void resettime(void);

/******************************************************************************************
* Function Name:     		wait
* Function Discription: 	��ʱ����
* params:  					time����ʱ��ʱ�䣬��λΪ�룬����0.01��
* return value: 			NULL
******************************************************************************************/
void wait(float time);

/******************************************************************************************
* Function Name:     		OpenLCD
* Function Discription:    	��ȡϵͳʱ��,���ص�ǰϵͳʱ��,��λ�룬��ȷ��0.01��
* params:  					NULL
* return value: 			���ص�ǰϵͳʱ�䣬��λΪ��
******************************************************************************************/
float seconds(void);

//#END REGION


//#REGION " FLASH��ȡ���� "
/******************************************************************************************
* Function Name:     		FLASH_Write
* Function Discription:    	������д��FLASH�У������ݵ����Ҳ�ɱ���
* params:  					uiAddress��д������ݵĵ�ַ����ΧΪ0-1023
							ucData��д���8λ���ݣ���Χ0-255
* return value: 			NULL
******************************************************************************************/
void FLASH_Write(unsigned int uiAddress, unsigned char ucData);

/******************************************************************************************
* Function Name:     		FLASH_Read
* Function Discription:    	��ȡFLASH�е�����
* params:  					uiAddress��д������ݵĵ�ַ����ΧΪ0-1023
* return value: 			���ظõ�ַ��Flash���д洢��8λ���ݣ���Χ0-255
******************************************************************************************/
unsigned char FLASH_Read(unsigned int uiAddress);

/******************************************************************************************
* Function Name:     		SetLED
* Function Discription:    	��������Ϩ��������ϵķ��������
* params:  					cState�����÷������������Ϊ1ʱ����LED��Ϊ0ʱϨ��LED��
* return value: 			NULL
******************************************************************************************/
void SetLED(char cState);

//#END REGION


//#REGION "����MF09�ĺ����⣬���Ƽ��³���ʹ�����к���"
/******************************************************************************************
* Function Name:     		Drive
* Function Discription:		ʹ�õ��MOTO_0��MOTO_1�������������˶�
* params:  					NULL
* return value: 			NULL
******************************************************************************************/
void Drive(signed char iVL, signed char iVR);

/******************************************************************************************
* Function Name:     		SetMotor
* Function Discription:		ͬʱ����4·����ٶȲ���
* params:  					iMask�����õ����������Ч��,iMask��ʾ������룻
									����0x1111��ʾͬʱΪ4·��������ٶ�ֵ��0x1100��ʾֻΪͨ��0��ͨ��1�ĵ�������ٶ�ֵ��������ͨ��2��ͨ��3���ٶ�ֵ��
							iV���趨�ĵ��0�Ĺ��ʣ��������ø�����ʾ��ת����Χ:-100~100��
* return value: 			NULL
******************************************************************************************/
void SetMotor(int iMask, signed char  iV0, signed char  iV1, signed char iV2, signed char iV3);
//void SetMotor(unsigned long iMask, signed char  iV0, signed char  iV1, signed char iV2, signed char iV3);
 
/******************************************************************************************
* Function Name:     		stop
* Function Discription:    	4·���ȫ��ֹͣ����
* params:  					NULL
* return value: 			NULL
******************************************************************************************/
void stop(void);

/******************************************************************************************
* Function Name:     		StopMotor
* Function Discription:    	ֹͣ��ѡͨ�����
* params:  					channel����Ҫֹͣ�ĵ��ͨ����ţ�
							��Χ��MOTO_0,MOTO_1,MOTO_2,MOTO_3
* return value: 			NULL
******************************************************************************************/
void StopMotor(unsigned char channel);

/******************************************************************************************
* Function Name:     		microphone
* Function Discription:		��ȡ��˷�ļ����
* params:  					Channel����˷����ӵ�ģ���ͨ����ȡֵ��Χ0-6
* return value: 			������˷�Ĳ��������
******************************************************************************************/
int microphone(char Channel);
//*************************************************************************************
// define Name:          	UART_WordLength_8D			
// define Description:	  	���ڳ�ʼ������,�����ֳ�
//*************************************************************************************
#define UART_WordLength_8D	      USART_WordLength_8b

//*************************************************************************************
// define Name:          	UART_StopBits_1			
// define Description:	  	���ڳ�ʼ������,ֹͣλ
//*************************************************************************************
#define UART_StopBits_1         USART_StopBits_1

//*************************************************************************************
// define Name:          	UART_StopBits_2			
// define Description:	  	���ڳ�ʼ������,ֹͣλ
//*************************************************************************************
#define UART_StopBits_2         USART_StopBits_2

//*************************************************************************************
// define Name:          	UART_Parity_No			
// define Description:	  	���ڳ�ʼ������,У��λ
//*************************************************************************************
#define UART_Parity_No	              USART_Parity_No

//*************************************************************************************
// define Name:          	UART_Parity_Even			
// define Description:	  	���ڳ�ʼ������,У��λ
//*************************************************************************************
#define UART_Parity_Even	      USART_Parity_Even

//*************************************************************************************
// define Name:          	UART_Parity_Odd			
// define Description:	  	���ڳ�ʼ������,У��λ
//*************************************************************************************
#define UART_Parity_Odd	              USART_Parity_Odd

/******************************************************************************************
* Function Name:     		SCI_Set
* Function Discription:		���ڳ�ʼ�����ú���
* params:  					����:unsigned int iPort
							����:��Ҫ��ʼ���Ĵ��ڱ��
							��Χ:UART_0,UART_1
							����:unsigned int iBaud
							����:�������趨
							��Χ:1200,4800,9600,38400,57600,115200
							����:unsigned char iCHK
							����:У��λ�趨
							��Χ:UART_Parity_No,UART_Parity_Even,UART_Parity_Odd
							����:unsigned int iData
							����:���ݳ����趨
							��Χ:UART_WordLength_8D
							����:unsigned int iStop
							����:ֹͣλ�趨
							��Χ:UART_StopBits_1,UART_StopBits_2
* return value: 			NULL
******************************************************************************************/
void SCI_Set(unsigned char iPort,unsigned int iBaud,unsigned int iCHK,unsigned int iData, unsigned int iStop);

/******************************************************************************************
* Function Name:     		serial_putchar
* Function Discription:    	���ڷ��ͺ���.�˺�����������,�����������ݺ����ŷ���
* params:  					cPort:���ڱ�ţ���Χ:UART_0,UART_1
							ucData:��Ҫ���͵����ݣ���Χ:0~255
* return value: 			NULL
******************************************************************************************/
void serial_putchar(char cPort, unsigned char ucData);

/******************************************************************************************
* Function Name:     		serial_getchar
* Function Discription:    	���ڽ��պ���,���ؽ��յ��ַ�.�˺�����������,�����յ����ݺ����ŷ���
* params:  					cPort:���ڱ�ţ���Χ��UART_0,UART_1
* return value: 			���ڽ��յ���8λ����
******************************************************************************************/
int serial_getchar(char cPort);

/******************************************************************************************
* Function Name:     		ad2voltage
* Function Discription:    	��ADC�Ķ�������Ϊ��ѹֵ��1023ʱ��Ӧ��ѹΪ5V
* params:  					ADC�Ĳ���ֵ����Χ 0 ~ 1023
* return value: 			�������ĵ�ѹֵ
******************************************************************************************/
float ad2voltage(int adcvalue);

//void Show_Clock(void);


/**LCD5110*******************************************************************************/
//LCD5110_Driver.h
/*---------------------------------------
��������LCD_Init 
���ܣ�5110LCD��ʼ��
�����������
���ز������� 
��д���ڣ�2010/09/21 
-----------------------------------------  */
void LCD_Init(void);

/**www***************/
/*------------------------------------------
��������LCD_clear
���ܣ�LCD��������
�����������
����ֵ����
��д���ڣ�2010/09/21 
--------------------------------------------*/
void LCD_Clear_5110(void);
/**www***************/

/*-------------------------------------------
��������LCD_set_XY
���ܣ�����LCD���꺯�� 
���������X��0��83  Y��0��5
����ֵ����
��д���ڣ�2010/09/21 
---------------------------------------------*/
void LCD_SetXY(unsigned char X, unsigned char Y);

/*--------------------------------------------
��������LCD_WriteByte
���ܣ�ʹ��SPI�ӿ�д���ݵ�LCD
���������UcData = д������ݣ�
		  DCMode Cmd = д����/����ѡ��
���ز�������
��д���ڣ�2010/09/21
----------------------------------------------*/
//==Һ��ʹ��ģ��SPI��ʽ��������===
void LCD_WriteByte(unsigned char UcData, DCMode Cmd);


//LCD5110_API.h
/*------------------------------------------
������:	LCD_WriteDot
���ܣ���һ���㵽��ȫ��������(��ȷ��λ���������ΪLCD������λ��)
�������:Dot_X = �����꣨0---83��
	     Dot_Y = �����꣨0---47��
		 LCD_DotMode Mode	���㷽ʽ (DOT_CLEAR-->������DOT_DRAW-->���㡢DOT_XOR-->ȡ��)
���أ���
���ߣ�whm
���ڣ�2010/09/21
------------------------------------------*/
void LCD_WriteDot(unsigned char Dot_X,unsigned char Dot_Y,LCD_DotMode Mode);


/*------------------------------------------
��������CommitBuffer
���ܣ��ύ���棬�ѵ�ǰ�����ϵ�����д��LCD��
��������
���أ���
���ߣ�whm
���ڣ�2010/09/26
------------------------------------------*/
//�ύ���溯�����������е���������LCD��RAM
void CommitBuffer( void );


/*------------------------------------
��������DrawLine
���ܣ����ݸ���������������껭ֱ��
���������Xbegin X���������      Ybegin Y���������
          Xend X���յ�����        Yend Y���յ�����
����ֵ����
���ߣ�whm
���ڣ�2010/09/26
------------------------------------*/
//��ֱ�ߺ��������Ը��ݸ����������㻭��ֱ��
void DrawLine(unsigned char Xbegin,unsigned char Ybegin,unsigned char Xend,unsigned char Yend);


//void LCD_WriteEnlish(unsigned char EnlishChar);
/*------------------------------------------
������:	LCD_WriteEnglish
���ܣ�дһ��Ӣ���ַ�
�������: EnglishChar  Ҫд��Ӣ���ַ�	 �������ַ�Ҫ�ӡ�����
���أ���
���ߣ�whm
���ڣ�2010/09/22
------------------------------------------*/
void LCD_WriteEnglish(unsigned char EnlishChar);

/**whm**********************************/
/*------------------------------------------
������:	LCD_WriteEnglish_str
���ܣ�дһ��Ӣ���ַ���
�������: Char  Ҫд��Ӣ���ַ���
���أ���
���ߣ�whm
���ڣ�2010/09/26
------------------------------------------*/
void LCD_WriteEnglishStr(unsigned char *s);
/**whm**********************************/

/*------------------------------------------
������:	LCD_WriteEnglishSring
���ܣ�дһ��Ӣ���ַ���
�������: EnlishChar  Ҫд��Ӣ���ַ� ��ע���ַ���Ҫ�ӡ�����
���أ���
���ߣ�whm
���ڣ�2010/09/22
------------------------------------------*/
void LCD_WriteEnglishSring(unsigned char X,unsigned char Y,char *s);



//����˵��:��ָ��λ����ʾ���ִ�. 
//�������:x=������,y=������,pCluster=���ִ�. 
unsigned char LcdHanzi(unsigned char x,unsigned char y,const unsigned char *pCluster);


//////////////////////
/******************************************************************************************
* Function Name:     		Printf
* Function Discription:    	����Ļ����ʾ���֣�Ҫ�����Ļ�����֮ǰ��LCD_Clear_5110();
*                                                    ��ZE���ڶ��ε��øú���ʱ��������
* params:  					const char Ҫ���Ƶ��ַ���
* return value: 			
******************************************************************************************/
int Printf(const char *fmt, ...);

/**WHM********************************************************************/
/************************************************************
* Function Name: 		 Printf_XY
* Function Description:  printf������һ��ʵ��,���Զ���λ����ʾ
* Params: 			     
* Return Value:		     NULL
************************************************************/
int Printf_XY(unsigned char X,unsigned char Y,const char *fmt, ...);
/**whm***************************************************************************/

/**LCD5110*******************************************************************************/

float GetChipTemp(void);

/******************************************************************************************
* Function Name:     	InitArmRobot
* Function Discription:    ��ʼ�������˵ĸ���Ӳ����Դ
* params:  			NULL
* return value: 			NULL
******************************************************************************************/
void InitArmRobot(void);

#define IO_IN  0
#define IO_OUT 1
#define IO_PWM 2
/******************************************************************************************
* Function Name:     		SetGPIOMode
* Function Discription:    	����GPIOģʽ
* params:  					Channel��ͨ���ţ���ΧΪ0-15
							      State��ģʽ����Χ IO_IN  0  ,IO_OUT 1 , IO_PWM 2
* return value: 			NULL
******************************************************************************************/
void SetGPIOMode(char Channel,char State);
extern vu32 AbsoluteTimeTicks;
void Set_LCD_LV(u8 level);

/**�й�RTC*****************************************************/
void Delay_trc(vu32 time );
/**
  * @brief  Main program.
  * @param  None
  * @retval : None
  */
int rtc_timedsp(void);

u32 Time_Regulate(void);

int fputc(int ch, FILE *f);

u8 USART_Scanf(u32 value);
/**�й�RTC*****************************************************/

/*******************************************************************************
* Function Name  : Time_Adjust
* Description    : Adjusts time.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void Time_Adjust(void);

int main_key_selection(void);

int main_c(void);
int sub_main(void);
int main_a(void);
//int main(void);//int main_b(void);


#define printf Printf
/**WHM************************/
#define printf_XY Printf_XY
/**WHM************************/
//#define main sub_main		
/**whm*****************************************************/
//#define main_b sub_main_b
//#define main_c sub_main_c
//#define main_key_selection sub_main_key_selection
/**whm*****************************************************/

#endif /* __ROBOTLIB_H*/

/******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE****/
