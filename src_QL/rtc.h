#ifndef __RTC_H
#define __RTC_H


#include "stm32f10x_lib.h"
#include <stdio.h>	 

#include "RobotLib.h"    //��һ�����Ҫ����ȻRTC.C�������һЩ��������������Ȼ������ʵ���޷�����


/* Private functions ---------------------------------------------------------*/
void Delay_trc(vu32 time );
void RTC_Configuration(void);

/**
  * @brief  Main program.
  * @param  None
  * @retval : None
  */
int rtc_timedsp(void);

u32 Time_Regulate(void);

int fputc(int ch, FILE *f);

u8 USART_Scanf(u32 value);

/*******************************************************************************
* Function Name  : Time_Adjust
* Description    : Adjusts time.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void Time_Adjust(void);

#endif
