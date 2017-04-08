#ifndef _LCD5110_H
#define _LCD5110_H

#include"stm32f10x_conf.h"

//宽高像素
#define LCD_X		84	
#define LCD_Y		48

//枚举 D/C模式选择 
typedef enum
{
    DC_CMD  = 0,	//写命令
	DC_DATA = 1		//写数据		
} DCMode;

//枚举 画点类型选择 
typedef enum
{
    DOT_CLEAR =  0,	//擦除
    DOT_DRAW  =  1,	//画点
    DOT_XOR =  2		//取反

} LCD_DotMode;

// 管脚电平配置 H: high, L: low
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


//SCE低电平有效
//#define LCD_SCE_Eable()     LCD_SCE_L()
//#define LCD_SCE_Disable()   LCD_SCE_H()

/*---------------------------------------
函数名：LCD_Init 
功能：5110LCD初始化
输入参数：无
返回参数：无 
编写日期：2010/09/21 
-----------------------------------------  */
void LCD_Init(void);

/**www***************/
/*------------------------------------------
函数名：LCD_clear
功能：LCD清屏函数
输入参数：无
返回值：无
编写日期：2010/09/21 
--------------------------------------------*/
void LCD_Clear_5110(void);
/**www***************/

/*-------------------------------------------
函数名：LCD_set_XY
功能：设置LCD坐标函数 
输入参数：X：0－83  Y：0－5
返回值：无
编写日期：2010/09/21 
---------------------------------------------*/
void LCD_SetXY(unsigned char X, unsigned char Y);

/*--------------------------------------------
函数名：LCD_WriteByte
功能：使用SPI接口写数据到LCD
输入参数：UcData = 写入的数据；
		  DCMode Cmd = 写数据/命令选择；
返回参数：无
编写日期：2010/09/21
----------------------------------------------*/
//==液晶使用模拟SPI方式传输数据===
void LCD_WriteByte(unsigned char UcData, DCMode Cmd);


#endif


