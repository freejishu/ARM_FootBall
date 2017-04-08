#ifndef __KEY_SELECTION_H
#define __KEY_SELECTION_H


#include "stm32f10x_lib.h"
#include <stdio.h>	 

#include "RobotLib.h"    //这一句很重要，不然RTC.C里调用了一些函数，编译器虽然不报错，实际无法运行

//extern void main_key_selection(void);
int main_key_selection(void);

#endif
