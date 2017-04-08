#ifndef _LCD5110_H
#define _LCD5110_H

#include"stm32f10x_conf.h"

//�������
#define LCD_X		84	
#define LCD_Y		48

//ö�� D/Cģʽѡ�� 
typedef enum
{
    DC_CMD  = 0,	//д����
	DC_DATA = 1		//д����		
} DCMode;

//ö�� ��������ѡ�� 
typedef enum
{
    DOT_CLEAR =  0,	//����
    DOT_DRAW  =  1,	//����
    DOT_XOR =  2		//ȡ��

} LCD_DotMode;

// �ܽŵ�ƽ���� H: high, L: low
// For STM32	

/***WHM*************************************************/
#define LCD_RST_DC_PORT  GPIOD
#define LCD_RST			GPIO_Pin_1 //PD1

#define LCD_DC			GPIO_Pin_14 //PD14

//config as spi2 
#define LCD_CLK_SDIN_PORT  GPIOD 
#define LCD_SCE			GPIO_Pin_0 //PD0

#define LCD_SDIN		GPIO_Pin_15 //PD15
#define LCD_SCLK	    GPIO_Pin_5 //PD5  //


#define LCD_RST_H()		GPIO_SetBits(GPIOD, LCD_RST)
#define LCD_RST_L()		GPIO_ResetBits(GPIOD , LCD_RST)

#define LCD_SCE_H()		GPIO_SetBits(GPIOD, LCD_SCE)
#define LCD_SCE_L()		GPIO_ResetBits(GPIOD, LCD_SCE)

#define LCD_DC_DATA()	GPIO_SetBits(GPIOD, LCD_DC)
#define LCD_DC_CMD()	GPIO_ResetBits(GPIOD, LCD_DC)

#define LCD_SDIN_H()	GPIO_SetBits(GPIOD, LCD_SDIN)
#define LCD_SDIN_L()	GPIO_ResetBits(GPIOD, LCD_SDIN)

#define LCD_SCLK_H()	GPIO_SetBits(GPIOD, LCD_SCLK)
#define LCD_SCLK_L()	GPIO_ResetBits(GPIOD, LCD_SCLK)
/***WHM*************************************************/


//SCE�͵�ƽ��Ч
//#define LCD_SCE_Eable()     LCD_SCE_L()
//#define LCD_SCE_Disable()   LCD_SCE_H()

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


#endif


