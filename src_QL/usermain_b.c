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

/* ��ض��壺
AI:
0-15 ��ʾ������3*16���� ���ϵ���
16-22 EYE_0 0-6
23-29 EYE_1 7-13
*/

/***ǰ�����۷ֱ��EYE0��EYE1*******************/
/***ǰ��������PSD�ֱ��AI0��AI1��AI2��AI3********/
#include "RobotLib.h"

int kk_cnt;
int HTZ_Ch,HTZ_In;	  //����ģʽ�£�ͨ���š�����ֵһ��ɼ�
/* 
��������ǰ���ǰ�����鸴�۰�д�ģ�7+7=14·��

��������Ӧ�ĸ����Ǵ�AI(16)��ʼ

��Ϊ���ǵĿ�������AI(0)~AI(15����Ԥ������������ģ�⴫�����õġ�
���۽ӿ��õ�AI(16)��ʼ��AI(29).

ǰ�����鸴������7+7=14·ģ��ڣ�AI(16)��AI(29).
*/ 

//////////////////////////////////////////////////////////////////////////////
//�������һ���԰�ͨ���ź�����ֵȡ�����ܶ�ʱ����Խ�Լһ��ʱ��////////////////
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
         //GetEyeMaxNum(2,0);   //����ģʽ�����յ�ͨ��0.001s�Ĳ������˺���ʱ����15.973ms  ,���Ƶ�ͨ����0.001s�����������40~50��

         s_GetEyeMaxNum(2,0);   //����ģʽ�����յ�ͨ��50�εĲ������˺���ʱ����17.85ms����    
                              //����ģʽ�����յ�ͨ��25�εĲ������˺���ʱ����14.60ms���� 
                           //����ģʽ�����յ�ͨ��10�εĲ������˺���ʱ����5.5ms����   .����10�εĲ��ô���������Ч��Ҫ��Щ��

         //GetEyeMaxNum(2,1);   //��ͨģʽ�����յ�ͨ��0.001ms�Ĳ������˺���ʱ��Ҳ��15.973ms                        

         //EyeChMax();      //�ǵ���ģʽ�����ú�������ʱ����0.52ms���� 

         //֤��������ʱ����Ҫ����ģ��ת����ʱ����
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
























