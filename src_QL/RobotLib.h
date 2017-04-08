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
// define Description:	  	复眼的宏定义,用于复眼扩展函数
//*************************************************************************************
#define EYE_0		0

//*************************************************************************************
// define Name:          	EYE_1			
// define Description:	  	复眼的宏定义,用于复眼扩展函数
//*************************************************************************************
#define EYE_1		1


//*************************************************************************************
// define Name:          	UART_0			
// define Description:	  	串口初始化定义,端口号
//*************************************************************************************
#define UART_0		0
 
//*************************************************************************************
// define Name:          	UART_1			
// define Description:	  	串口初始化定义,端口号
//*************************************************************************************
#define UART_1		1

//*************************************************************************************
// define Name:          	PLL_X			
// define Description:	  	系统时钟频率
//*************************************************************************************
#define PLL_72		9
#define PLL_64		8
#define PLL_56		7
#define PLL_48		6
#define PLL_40		5
#define PLL_32		4
#define PLL_24		3
#define PLL_16		2

/**20110808加入*****************************************/
void RCC_Configuration(void);
void GPIO_Configuration(void);
void NVIC_Configuration(void);
/**20110808加入*****************************************/

/******************************************************************************************
* Function Name:      		MCLK_Config
* Function Discription:  	设CPU运行时的时钟频率，可根据功耗和速度的要求来设置。控制器提供了8个可用频率，等级为2-9。对应CPU时钟频率分别为16M，24M……72M。
* params:  		   			MCLK_Clock取值范围2-9，默认为9。
* return value: 			NULL
******************************************************************************************/
void MCLK_Config(char MCLK_Clock);

/******************************************************************************************
* Function Name:     		LCDControl
* Function Discription:    	开关LCD屏幕显示
* params:  					cState：范围0或1，0表明关掉LCD显示；1表明打开LCD显示
* return value: 			NULL
******************************************************************************************/
//void LCDControl (char cState);

/******************************************************************************************
* Function Name:     		CLRLCD
* Function Discription:    	清除屏幕当前的显示
* params:  					NULL
* return value: 			NULL
*****************************************************************************************/
//void CLRLCD(void);

/******************************************************************************************
* Function Name:     		Printf
* Function Discription:    	在屏幕上绘制文字，第二次调用该函数时会清屏
* params:  					const char 要绘制的字符串
* return value: 			
******************************************************************************************/
//int Printf(const char *fmt, ...);

/******************************************************************************************
* Function Name:     		cout
* Function Discription:    	在屏幕上绘制文字，但第二次调用该函数时不会清屏，一直写到屏幕底部才会清掉一行
* params:  					const char 要绘制的字符串
* return value: 			
******************************************************************************************/
//int cout(const char *fmt, ...);

/******************************************************************************************
* Function Name:     		DrawPixel
* Function Discription:    	在屏幕缓冲区上的绘制一个像素的点
* params:  					int X X轴坐标
							int Y Y轴坐标
							int color 所画点的颜色
							库函数中已经定义好相关颜色的宏定义，故color取值范围为White、Black、Grey、
							Blue、Blue2、Red、Magenta、Green、Cyan、Yellow。
* return value: 			NULL
******************************************************************************************/
//void DrawPixel (int x, int y, int color); 

/******************************************************************************************
* Function Name:     		DrawLine
* Function Discription:    	在屏幕缓冲区上的绘制一条直线,从(X1,Y1)到(X2,Y2)
* params:  					int X1 端点1的X轴坐标
							int Y1 端点1的Y轴坐标
							int X2 端点2的X轴坐标
							int Y2 端点2的Y轴坐标
							int color 所画线的颜色，取值范围为White、Black、Grey、Blue、Blue2、Red、
							Magenta、Green、Cyan、Yellow
* return value: 			NULL
******************************************************************************************/
//void DrawLine(int x1,int y1,int x2,int y2,int color);

/******************************************************************************************
* Function Name:     		DrawRect
* Function Discription:    	在屏幕缓冲区上的绘制一个矩形，XY为坐标最小的点
* params:  					int X 坐标最小的点的X轴坐标；
							int Y 坐标最小的点的Y轴坐标；
							int width 矩形的宽度；
							int height 矩形的高度；
							int color 矩形的颜色，取值范围为White、Black、Grey、Blue、Blue2、Red、
							Magenta、Green、Cyan、Yellow
* return value: 			NULL
******************************************************************************************/
//void DrawRect(int x,int y,int width,int height,int color);





/******************************************************************************************
* Function Name:     		SetMoto
* Function Discription:    	启动某一个通道电机，
* params:  					cChannel：通道号，分别为0，1，2，3；
							cSpeed：速度值，范围为-100~100。
* return value: 			NULL
******************************************************************************************/
void SetMoto(char cChannel, signed char cSpeed);

/******************************************************************************************
* Function Name:     		SetAllMoto
* Function Discription:    	同时设置4路电机参数
* params:  					iMask为掩码，例如0x1111表示同时为4路电机设置速度值，
							0x1100表示只为通道0和通道1的电机设置速度值，不设置通道2和通道3的速度值。
							cSpeed分别为4路通道电机的速度值，范围为-100~100。
* return value: 			NULL
******************************************************************************************/
void SetAllMoto(int iMask, signed char cSpeed0, signed char cSpeed1, signed char cSpeed2, signed char cSpeed3);
 
/******************************************************************************************
* Function Name:     		StopMoto
* Function Discription:    	停止所选通道电机
* params:  					channel 所停止的电机的通道号
* return value: 			NULL
******************************************************************************************/
void StopMoto(char cChannel);

/******************************************************************************************
* Function Name:     		StopAllMoto
* Function Discription:    	4路电机全部停止运行
* params:  					NULL
* return value: 			NULL
******************************************************************************************/
void StopAllMoto(void);
//#END REGION


//#REGION " 读取模拟口/数字口"

/******************************************************************************************
* Function Name:     		AI
* Function Discription:    	读取模拟口通道的输入。
* params:  					cChannel为通道号，范围0-20；
* return value: 			返回AD采样值，范围-1023 ~ 1023，对应-5V ~ +5V的电压值。
******************************************************************************************/
int AI(char cChannel);

/******************************************************************************************
* Function Name:     		DI
* Function Discription:    	读取数字口通道的输入。
* params:  					cChannel为通道号，范围0-7；
* return value: 			返回0或1。
******************************************************************************************/
char DI(char cChannel);

//#END REGION


//#REGION "复眼"
/******************************************************************************************
* Function Name:     		EyeInMin
* Function Discription:    	读取两个复眼传感器在360度方向上读数最小的值
* params:  					NULL
* return value: 			返回读数最小的值
******************************************************************************************/
int EyeInMin(void);

/******************************************************************************************
* Function Name:     		EyeChMin
* Function Discription:    	读取两个复眼传感器在360度方向上最小的值所在方向编号
* params:  					NULL
* return value: 			读值最小的通道的通道号，范围为0-13
******************************************************************************************/
int EyeChMin(void);

/******************************************************************************************
* Function Name:     		EyeInMax
* Function Discription:    	读取两个复眼传感器在360度方向上读数最大的值（通常球在哪个方向，哪个方
							向光照越强，复眼探头的读数越大）
* params:  					NULL
* return value: 			返回读值最大值
******************************************************************************************/
int EyeInMax(void);

/******************************************************************************************
* Function Name:     		EyeChMax
* Function Discription:    	读取两个复眼传感器在360度方向上最大的值所在方向编号
* params:  					NULL
* return value: 			返回读值最大的通道号，范围为0-13
******************************************************************************************/
int EyeChMax(void);

/******************************************************************************************
* Function Name:     		EyeInMinEx
* Function Discription:    	读取指定复眼传感器在180度方向上读数最小的值
* params:  					所选的复眼号，范围为EYE_0或EYE_1。
* return value: 			返回该复眼中读数最小的值
******************************************************************************************/
int EyeInMinEx(char cEYE);

/******************************************************************************************
* Function Name:     		EyeChMinEx
* Function Discription:    	读取指定复眼传感器在180度方向上最小的值所在方向编号
* params:  					所选的复眼号，范围为EYE_0或EYE_1
* return value: 			返回该复眼中读数最小所在方向的编号，范围0 - 6。
******************************************************************************************/
int EyeChMinEx(char cEYE);
	
/******************************************************************************************
* Function Name:     		EyeInMaxEx
* Function Discription:    	读取指定复眼传感器在180度方向上读数最大的值
* params:  					所选的复眼号，范围为EYE_0或EYE_1
* return value: 			返回该复眼中读数最大的值
******************************************************************************************/
int EyeInMaxEx(char cEYE);

/******************************************************************************************
* Function Name:     		EyeChMaxEx
* Function Discription:    	读取指定复眼传感器在180度方向上最大的值所在方向编号
* params:  					所选的复眼号，范围为EYE_0或EYE_1
* return value: 			返回该复眼中读数最大所在方向的编号，范围0 - 6
******************************************************************************************/
int EyeChMaxEx(char cEYE);

//#END REGION


//#REGION " DO 数字输出口"
/******************************************************************************************
* Function Name:     		SetDO
* Function Discription:    	设定数字输出
* params:  					cChannel 数字输出的通道号，范围为0-7。
							cState 数字输出状态，1表明输出高电平，0表明输出低电平
* return value: 			NULL
******************************************************************************************/
void SetDO(char cChannel, char cState);

/******************************************************************************************
* Function Name:     		SetServo
* Function Discription:    	把数字输出端口作为伺服电机控制信号端口，控制驱动伺服电机转到特定角度，
							请注意，如果接两个以上伺服电机，伺服电机需另外接功率驱动卡。
* params:  					cChannel 数字输出的通道号，范围为0-7。
							ucAngle 要转到的角度，范围为0-180。
							cSpeed 转动的角速度，范围为0-100
* return value: 			NULL
******************************************************************************************/
//void SetServo(char cChannel,unsigned char ucAngle,char cSpeed);
void SetServo(char Channel_p,char Angle_p,char Speed_p);
void InitSV(void);
//#END REGION


//#REGION " I2C "
/******************************************************************************************
* Function Name:     		InitI2C
* Function Discription:    	I2C主机方式初始化
* params:  					uiI2CFreq： I2C总线频率，一般范围为0-400000，默认为I2CFEC。
* return value: 			NULL
******************************************************************************************/
void InitI2C(unsigned int uiI2CFreq);

/******************************************************************************************
* Function Name:     		I2C_Save
* Function Discription:    	向I2C总线上地址为EepromAddr的器件中软地址为addr的单元
写入一个字节的数据
* params:  					ucEepromAddr：I2C总线上的器件硬件地址，范围：0~255
							ucAddr：I2C总线上的器件的软地址，范围:0~255
ucData：					要发送的数据，八位，范围:0~255
* return value: 			如果写入成功返回1，写入失败返回0
******************************************************************************************/
u16 I2C_Save(unsigned char ucEepromAddr, unsigned char ucAddr, unsigned char ucData);
//char I2C_Save(unsigned char ucEepromAddr, unsigned char ucAddr, unsigned char ucData);

/******************************************************************************************
* Function Name:     		OpenLCD
* Function Discription:   	读取I2C总线上地址为EepromAddr的器件中软地址为addr的单元的数据
* params:  					ucEepromAddr：I2C总线上的器件硬件地址，范围：0~255
							ucAddr：I2C总线上的器件的软地址，范围:0~255
* return value: 			返回8位数据
******************************************************************************************/
int I2C_Read(unsigned char ucEepromAddr, unsigned char ucAddr);
//unsigned char I2C_Read(unsigned char ucEepromAddr, unsigned char ucAddr);

/******************************************************************************************\
* Function Name:     	Sonar_Dis
* Function Discription:    读取I2C总线上超声模块的距离读数
* params:  			NULL
* return value: 			指南针角速度，范围：0-255cm
\******************************************************************************************/
int Sonar_Dis(void);
//#END REGION


//#REGION " I2C接口的数字指南针"

/******************************************************************************************
* Function Name:     		Compass_Degree
* Function Discription:   	读取I2C总线上指南针模块的角度读数
* params:  					NULL
* return value: 			指南针角速度，范围：0-359
******************************************************************************************/
int Compass_Degree(void);

//#END REGION


//#REGION " UART串口"
/******************************************************************************************
* Function Name:     		UART_Set
* Function Discription:    	串口初始化设置函数
* params:  					名称:unsigned int iPort
							描述:需要初始化的串口编号
							范围:UART_0,UART_1
							名称:unsigned int uiBaud
							描述:波特率设定，默认9600
							范围:1200,4800,9600,38400,57600,115200
* return value: 			NULL
******************************************************************************************/
void UART_Set(char cPort,unsigned int uiBaud);

/******************************************************************************************
* Function Name:     		UART_Check
* Function Discription:    	串口数据查询, 检测串口是否收到数据
* params:  					cPort：需要初始化的串口编号，范围:UART_0,UART_1
* return value: 			如果串口收到数据就返回1，没收到数据就返回0
******************************************************************************************/
char UART_Check(char cPort);

/******************************************************************************************
* Function Name:     		SCI_Send
* Function Discription:    	使用串口发送单个字节数据,此函数是非阻塞型,无论串口发送完毕与否,都直接返回
* params:  					cPort:串口编号，范围:UART_0,UART_1
							ucData:需要发送的数据，范围:0~255
* return value: 			NULL
******************************************************************************************/
void SCI_Send(char cPort, unsigned char ucData);
 
/******************************************************************************************
* Function Name:     		SCI_Receive
* Function Discription:     串口接收函数,此函数是非阻塞型,无论串口接收完毕与否,都直接返回
* params:  					cPort:串口编号，范围:UART_0,UART_1
* return value: 			串口接收到的8位数据
******************************************************************************************/
unsigned char SCI_Receive(char cPort);

//#END REGION


//#REGION "按钮"
/******************************************************************************************
* Function Name:     		Get_Button
* Function Discription:    	得到按钮的状态，打开
* params:  					cKey：按钮的号码。本控制器只有1个按钮，故cKey为0。
* return value: 			返回0或1，返回1表示有按键按下，返回0表示没有按键按下。
******************************************************************************************/
int Get_Button(char cKey);

//#END REGION


//#REGION "系统时间"
/******************************************************************************************
* Function Name:     		resettime
* Function Discription:    	系统时间设置为0
* params:  					NULL
* return value: 			NULL
******************************************************************************************/
void resettime(void);

/******************************************************************************************
* Function Name:     		wait
* Function Discription: 	延时函数
* params:  					time：延时的时间，单位为秒，精度0.01秒
* return value: 			NULL
******************************************************************************************/
void wait(float time);

/******************************************************************************************
* Function Name:     		OpenLCD
* Function Discription:    	读取系统时间,返回当前系统时间,单位秒，精确到0.01秒
* params:  					NULL
* return value: 			返回当前系统时间，单位为秒
******************************************************************************************/
float seconds(void);

//#END REGION


//#REGION " FLASH存取操作 "
/******************************************************************************************
* Function Name:     		FLASH_Write
* Function Discription:    	将数据写入FLASH中，该数据掉电后也可保存
* params:  					uiAddress：写入的数据的地址，范围为0-1023
							ucData：写入的8位数据，范围0-255
* return value: 			NULL
******************************************************************************************/
void FLASH_Write(unsigned int uiAddress, unsigned char ucData);

/******************************************************************************************
* Function Name:     		FLASH_Read
* Function Discription:    	读取FLASH中的数据
* params:  					uiAddress：写入的数据的地址，范围为0-1023
* return value: 			返回该地址的Flash当中存储的8位数据，范围0-255
******************************************************************************************/
unsigned char FLASH_Read(unsigned int uiAddress);

/******************************************************************************************
* Function Name:     		SetLED
* Function Discription:    	点亮或者熄灭控制器上的发光二极管
* params:  					cState：设置发光二极管亮灭。为1时点亮LED，为0时熄灭LED。
* return value: 			NULL
******************************************************************************************/
void SetLED(char cState);

//#END REGION


//#REGION "兼容MF09的函数库，不推荐新程序使用下列函数"
/******************************************************************************************
* Function Name:     		Drive
* Function Discription:		使用电机MOTO_0和MOTO_1，驱动机器人运动
* params:  					NULL
* return value: 			NULL
******************************************************************************************/
void Drive(signed char iVL, signed char iVR);

/******************************************************************************************
* Function Name:     		SetMotor
* Function Discription:		同时设置4路电机速度参数
* params:  					iMask：设置电机参数的有效性,iMask表示电机掩码；
									例如0x1111表示同时为4路电机设置速度值，0x1100表示只为通道0和通道1的电机设置速度值，不设置通道2和通道3的速度值。
							iV：设定的电机0的功率，其中设置负数表示反转，范围:-100~100。
* return value: 			NULL
******************************************************************************************/
void SetMotor(int iMask, signed char  iV0, signed char  iV1, signed char iV2, signed char iV3);
//void SetMotor(unsigned long iMask, signed char  iV0, signed char  iV1, signed char iV2, signed char iV3);
 
/******************************************************************************************
* Function Name:     		stop
* Function Discription:    	4路电机全部停止运行
* params:  					NULL
* return value: 			NULL
******************************************************************************************/
void stop(void);

/******************************************************************************************
* Function Name:     		StopMotor
* Function Discription:    	停止所选通道电机
* params:  					channel：需要停止的电机通道编号，
							范围：MOTO_0,MOTO_1,MOTO_2,MOTO_3
* return value: 			NULL
******************************************************************************************/
void StopMotor(unsigned char channel);

/******************************************************************************************
* Function Name:     		microphone
* Function Discription:		读取麦克风的监测结果
* params:  					Channel：麦克风连接的模拟口通道，取值范围0-6
* return value: 			返回麦克风的采样结果。
******************************************************************************************/
int microphone(char Channel);
//*************************************************************************************
// define Name:          	UART_WordLength_8D			
// define Description:	  	串口初始化定义,数据字长
//*************************************************************************************
#define UART_WordLength_8D	      USART_WordLength_8b

//*************************************************************************************
// define Name:          	UART_StopBits_1			
// define Description:	  	串口初始化定义,停止位
//*************************************************************************************
#define UART_StopBits_1         USART_StopBits_1

//*************************************************************************************
// define Name:          	UART_StopBits_2			
// define Description:	  	串口初始化定义,停止位
//*************************************************************************************
#define UART_StopBits_2         USART_StopBits_2

//*************************************************************************************
// define Name:          	UART_Parity_No			
// define Description:	  	串口初始化定义,校验位
//*************************************************************************************
#define UART_Parity_No	              USART_Parity_No

//*************************************************************************************
// define Name:          	UART_Parity_Even			
// define Description:	  	串口初始化定义,校验位
//*************************************************************************************
#define UART_Parity_Even	      USART_Parity_Even

//*************************************************************************************
// define Name:          	UART_Parity_Odd			
// define Description:	  	串口初始化定义,校验位
//*************************************************************************************
#define UART_Parity_Odd	              USART_Parity_Odd

/******************************************************************************************
* Function Name:     		SCI_Set
* Function Discription:		串口初始化设置函数
* params:  					名称:unsigned int iPort
							描述:需要初始化的串口编号
							范围:UART_0,UART_1
							名称:unsigned int iBaud
							描述:波特率设定
							范围:1200,4800,9600,38400,57600,115200
							名称:unsigned char iCHK
							描述:校验位设定
							范围:UART_Parity_No,UART_Parity_Even,UART_Parity_Odd
							名称:unsigned int iData
							描述:数据长度设定
							范围:UART_WordLength_8D
							名称:unsigned int iStop
							描述:停止位设定
							范围:UART_StopBits_1,UART_StopBits_2
* return value: 			NULL
******************************************************************************************/
void SCI_Set(unsigned char iPort,unsigned int iBaud,unsigned int iCHK,unsigned int iData, unsigned int iStop);

/******************************************************************************************
* Function Name:     		serial_putchar
* Function Discription:    	串口发送函数.此函数是阻塞型,即发送完数据函数才返回
* params:  					cPort:串口编号，范围:UART_0,UART_1
							ucData:需要发送的数据，范围:0~255
* return value: 			NULL
******************************************************************************************/
void serial_putchar(char cPort, unsigned char ucData);

/******************************************************************************************
* Function Name:     		serial_getchar
* Function Discription:    	串口接收函数,返回接收的字符.此函数是阻塞型,即接收到数据函数才返回
* params:  					cPort:串口编号，范围：UART_0,UART_1
* return value: 			串口接收到的8位数据
******************************************************************************************/
int serial_getchar(char cPort);

/******************************************************************************************
* Function Name:     		ad2voltage
* Function Discription:    	将ADC的读数计算为电压值，1023时对应电压为5V
* params:  					ADC的采样值，范围 0 ~ 1023
* return value: 			浮点数的电压值
******************************************************************************************/
float ad2voltage(int adcvalue);

//void Show_Clock(void);


/**LCD5110*******************************************************************************/
//LCD5110_Driver.h
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


//LCD5110_API.h
/*------------------------------------------
函数名:	LCD_WriteDot
功能：画一个点到入全屏缓存中(精确定位，坐标可以为LCD上任意位置)
输入参数:Dot_X = 横坐标（0---83）
	     Dot_Y = 纵坐标（0---47）
		 LCD_DotMode Mode	画点方式 (DOT_CLEAR-->擦除、DOT_DRAW-->画点、DOT_XOR-->取反)
返回：无
作者：whm
日期：2010/09/21
------------------------------------------*/
void LCD_WriteDot(unsigned char Dot_X,unsigned char Dot_Y,LCD_DotMode Mode);


/*------------------------------------------
函数名：CommitBuffer
功能：提交缓存，把当前缓存上的数据写到LCD上
参数：无
返回：无
作者：whm
日期：2010/09/26
------------------------------------------*/
//提交缓存函数，将缓存中的数据送入LCD的RAM
void CommitBuffer( void );


/*------------------------------------
函数名：DrawLine
功能：根据给定的两个点的坐标画直线
输入参数：Xbegin X轴起点坐标      Ybegin Y轴起点坐标
          Xend X轴终点坐标        Yend Y轴终点坐标
返回值：无
作者：whm
日期：2010/09/26
------------------------------------*/
//画直线函数，可以根据给出的两个点画出直线
void DrawLine(unsigned char Xbegin,unsigned char Ybegin,unsigned char Xend,unsigned char Yend);


//void LCD_WriteEnlish(unsigned char EnlishChar);
/*------------------------------------------
函数名:	LCD_WriteEnglish
功能：写一个英文字符
输入参数: EnglishChar  要写的英文字符	 ，助于字符要加‘’号
返回：无
作者：whm
日期：2010/09/22
------------------------------------------*/
void LCD_WriteEnglish(unsigned char EnlishChar);

/**whm**********************************/
/*------------------------------------------
函数名:	LCD_WriteEnglish_str
功能：写一个英文字符串
输入参数: Char  要写的英文字符串
返回：无
作者：whm
日期：2010/09/26
------------------------------------------*/
void LCD_WriteEnglishStr(unsigned char *s);
/**whm**********************************/

/*------------------------------------------
函数名:	LCD_WriteEnglishSring
功能：写一个英文字符串
输入参数: EnlishChar  要写的英文字符 ，注意字符串要加“”号
返回：无
作者：whm
日期：2010/09/22
------------------------------------------*/
void LCD_WriteEnglishSring(unsigned char X,unsigned char Y,char *s);



//函数说明:在指定位置显示汉字串. 
//函数入口:x=横坐标,y=纵坐标,pCluster=汉字串. 
unsigned char LcdHanzi(unsigned char x,unsigned char y,const unsigned char *pCluster);


//////////////////////
/******************************************************************************************
* Function Name:     		Printf
* Function Discription:    	在屏幕上显示文字，要清屏的话可在之前加LCD_Clear_5110();
*                                                    【ZE：第二次调用该函数时会清屏】
* params:  					const char 要绘制的字符串
* return value: 			
******************************************************************************************/
int Printf(const char *fmt, ...);

/**WHM********************************************************************/
/************************************************************
* Function Name: 		 Printf_XY
* Function Description:  printf函数的一个实现,可自定义位置显示
* Params: 			     
* Return Value:		     NULL
************************************************************/
int Printf_XY(unsigned char X,unsigned char Y,const char *fmt, ...);
/**whm***************************************************************************/

/**LCD5110*******************************************************************************/

float GetChipTemp(void);

/******************************************************************************************
* Function Name:     	InitArmRobot
* Function Discription:    初始化机器人的各种硬件资源
* params:  			NULL
* return value: 			NULL
******************************************************************************************/
void InitArmRobot(void);

#define IO_IN  0
#define IO_OUT 1
#define IO_PWM 2
/******************************************************************************************
* Function Name:     		SetGPIOMode
* Function Discription:    	设置GPIO模式
* params:  					Channel：通道号，范围为0-15
							      State：模式，范围 IO_IN  0  ,IO_OUT 1 , IO_PWM 2
* return value: 			NULL
******************************************************************************************/
void SetGPIOMode(char Channel,char State);
extern vu32 AbsoluteTimeTicks;
void Set_LCD_LV(u8 level);

/**有关RTC*****************************************************/
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
/**有关RTC*****************************************************/

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
