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
/* 
这个程序是按照前后两块复眼板写的（7+7=14路）

这个程序对应的复眼是从AI(16)开始

因为我们的控制器的AI(0)~AI(15)是预留其他给其他模拟传感器用的。
复眼接口用的AI(16)开始到AI(29).

前后两块复眼用了7+7=14路模拟口：AI(16)到AI(29).
*/ 

#include "RobotLib.h"
unsigned int gi_1=0;  /*CMP指示相对于机器人的方位标记*/
unsigned int eye_ch_all=0; /*复眼通道*/

unsigned int psdf=0,psdb=0,psdl=0,psdr=0;  /*前、后、左、右红外测距*/

unsigned int back_psd_distance=0;  /*后红外测距B*/
unsigned int psd_heng_cha=0; 
unsigned int psd_heng_middle=200;

int compass_1=0;    //unsigned int compass_1=0;  /*指南针*/

float power_speed=1.0,t;
unsigned int ball=20;/*有没有球*/
unsigned int ball_huoyan=0; //火焰 待测 
unsigned int psdf_kaqiang=550; //火焰 待测 
unsigned int eye_ch_num=0;//, eye_ch_left=0, eye_ch_right=0 ,gi_left_right=0;
//unsigned int eye_ch_max_s=0, tag_ball_distance=0,my_cha=0;

unsigned int Run_LastPost_1=0;  /*左轮上次提交数值*/
unsigned int Run_LastPost_2=0;  /*右轮上次提交数值*/

//unsigned int Run_Ball_0=0;  /*复眼位置记录*/
//unsigned int Run_Ball_1=0;  
//unsigned int Run_Ball_2=0;  

unsigned int my_status=0;

//unsigned int left_speed=0;
//unsigned int right_speed=0;

unsigned int eye_ch_du=0;
unsigned int eye_ch_cmp=0;

unsigned int ball_distance=0;  /*球的远近*/  /*正前或正后方火焰值*/
unsigned int ball_light_jb=400;/*拨球亮度要求*/
///////////////////////////////////////////////////////////////

int eye_jin_zhong=300;
int eye_zhong_yuan=300;
int eye_yuan_jin=300;

int time=0;
int key=0;

int my_EyeChMax()
{
	int ch=0;
	//Run_Ball_2 = Run_Ball_1;
	//Run_Ball_1 = Run_Ball_0;
	ch = EyeChMax();
	//Run_Ball_0 = ch;
	return ch;
}



void Run(int sl,int sr)   //可设置功率,范围-100--100   可通过左下和右下按钮控制电机的停、转
{	
	//Run_LastPost_1=sl;
	//Run_LastPost_2=sr;
	//SetMoto(0,sl*power_speed);
	//SetMoto(1,sr*power_speed);
	if(sl<0)sl=0;
	if(sr<0)sr=0;
	if(Run_LastPost_1 != sl) SetMoto(0,sl);
	if(Run_LastPost_2 != sr) SetMoto(1,sr); 

	//SetMoto(0,sl);
	//SetMoto(1,sr); 
}


void sub_findfootball(){

	//eye_ch_all=GetEyeMaxNum(2,0); //获取360上复眼方向
	eye_ch_all= EyeChMax();
	eye_ch_num=GetSingleEye(eye_ch_all,0); //获取单个 
	//LCD_Clear_5110();
	//printf_XY(0,1,"EYE_CH=%d",eye_ch_all);
	//printf_XY(0,2,"EYE_IN=%d",eye_ch_num);
	 
	//if(AI(5) > ball_huoyan) return 0;//进攻 
	
	//分块控制
	//                                  近距离             远距离 
	//if(eye_ch_num > eye_yuan_jin){    
	//	if(eye_ch_num > eye_yuan_jin) Run(0,100);   else Run(0,100);
	//}else 
	if(eye_ch_all==1){
		Run(10,90);
	}else if(eye_ch_all==2){
		Run(30,90); 
	}else if(eye_ch_all==3){
		Run(90,90);
	}else if(eye_ch_all==4){
		Run(90,30); 
	}else if(eye_ch_all==5){
		Run(90,10); 
	}else if(eye_ch_all==6){
		Run(90,0);   
	}else if(eye_ch_all==7){
		Run(90,-10); 
	}else if(eye_ch_all==8){
		Run(90,-30);
	}else if(eye_ch_all==9){
		Run(90,-60); 
	}else if(eye_ch_all==10){
		Run(90,-100);
	}else if(eye_ch_all==11){
		Run(-60,90); 
	}else if(eye_ch_all==12){
		Run(-30,90);
	}else if(eye_ch_all==13){
		Run(0,90);   
	}else{ 
		Run(0,90); 
	}

}

int sub_main(void)
{
	LCD_Clear_5110();
	//printf_XY(0,0,"ftbl a 0.13");
	//my_status=1;//1-寻球 2-进攻 3-防守 
	while(1)
	{   
		//while(EyeInMax() < ball){Run_back();}
		sub_findfootball();
		wait(0.02);
		//while (1) if(Get_Button(0)==1) break;
	}
}




























