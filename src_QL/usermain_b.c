/*
#include "RobotLib.h"

void main_b()
{
    resettime();	
	while(1)
	{	 
		SetLED(0);
		wait(0.5);
		SetLED(1);
		wait(0.5);

		LCD_Clear_5110();
		printf("%d",Compass_Degree());	
	} 
}
*/

/* 相关定义：
AI:
0-15 显示屏左侧的3*16个口 由上到下
16-22 EYE_0 0-6
23-29 EYE_1 7-13
*/

/***前、后复眼分别接EYE0、EYE1*******************/
/***前、后左右PSD分别接AI0、AI1、AI2、AI3********/
#include "RobotLib.h"

int kk_cnt;
int HTZ_Ch,HTZ_In;	  //调制模式下，通道号、亮度值一起采集
/* 
这个程序是按照前后两块复眼板写的（7+7=14路）

这个程序对应的复眼是从AI(16)开始

因为我们的控制器的AI(0)~AI(15）是预留其他给其他模拟传感器用的。
复眼接口用的AI(16)开始到AI(29).

前后两块复眼用了7+7=14路模拟口：AI(16)到AI(29).
*/ 

//////////////////////////////////////////////////////////////////////////////
//这个函数一次性把通道号和亮度值取出，很多时候可以节约一半时间////////////////
int H_GetEyeMaxNum_Value(int n,int m)
{
	int i,j,temp;
	//int temp_id;
	int tv[14];
	int tid[14];
	int num=7;
    if(n>2) return 0;
    if(n==2)
    {
    	n=0;
    	num=14;
    }
    else
    {
    	num=7;
    }  
	for(i=0;i<num;i++)
	{
		tv[i]=s_GetSingleEye(i+7*n,m);
		tid[i]=i;
	}
	for(i=0;i<num-1;i++)
	{
 		for(j=i+1;j<num;j++)   
		{
			if(tv[i]>tv[j])
			{
				temp=tv[i];
				tv[i]=tv[j];
				tv[j]=temp;   
				temp=tid[i];
				tid[i]=tid[j];
				tid[j]=temp;  					       		          		
			}
		} 
	}
    //return tid[num-1];
	HTZ_Ch=tid[num-1];
	HTZ_In=tv[num-1];
	return 0;
}

int sub_main(void)
{			

	LCD_Clear_5110();
	printf("football a 0.0.1");

	while(1)
    {          
        //printf("%d %d \n%d %d \n",GetEyeMaxNum(0,0),GetEyeMaxValue(0,0),GetEyeMaxNum(0,1),GetEyeMaxValue(0,1));
      /*
        resettime();         
      for(kk_cnt=0;kk_cnt<1000;kk_cnt++)
      {
         //GetEyeMaxNum(2,0);   //调制模式，按照单通道0.001s的采样，此函数时间在15.973ms  ,估计单通道里0.001s里采样次数在40~50次

         s_GetEyeMaxNum(2,0);   //调制模式，按照单通道50次的采样，此函数时间在17.85ms左右    
                              //调制模式，按照单通道25次的采样，此函数时间在14.60ms左右 
                           //调制模式，按照单通道10次的采样，此函数时间在5.5ms左右   .但是10次的采用次数抗干扰效果要差些。

         //GetEyeMaxNum(2,1);   //普通模式，按照单通道0.001ms的采样，此函数时间也在15.973ms                        

         //EyeChMax();      //非调制模式【常用函数】，时间在0.52ms左右 

         //证明，整个时间主要是在模拟转换的时间上
      }
      LCD_Clear_5110(); 
      printf_XY(0,1,"tim=%f",seconds());
      while(1);
      */

      H_GetEyeMaxNum_Value(2,0);     

      LCD_Clear_5110();  
      //Printf("ch=%d,ch=%d,"MY_EyeChMax()); 
      printf_XY(0,1,"Tch=%d",GetEyeMaxNum(2,0));   printf_XY(42,1,"Tin=%d",GetEyeMaxValue(2,0)); 
      printf_XY(0,2,"10C=%d",s_GetEyeMaxNum(2,0));   printf_XY(42,2,"10I=%d",s_GetEyeMaxValue(2,0));//
      printf_XY(0,3,"ch=%d",GetEyeMaxNum(2,1));     printf_XY(42,3,"in=%d",GetEyeMaxValue(2,1));
      printf_XY(0,4,"HCh=%d",HTZ_Ch);     printf_XY(42,4,"HIn=%d",HTZ_In);
      printf_XY(0,5,"T10=%d",GetSingleEye(10,0));     printf_XY(44,5,"10C=%d",GetSingleEye(10,1));
      //GetSingleEye(int n,int m)
      wait(0.1);
    }
}
























