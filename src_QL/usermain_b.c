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
unsigned int ball=80;/*有没有球*/
unsigned int ball_huoyan=0; //火焰 待测 
unsigned int psdf_kaqiang=550; //火焰 待测 
unsigned int eye_ch_num=0, eye_ch_left=0, eye_ch_right=0 ,gi_left_right=0;
unsigned int eye_ch_max_s=0, tag_ball_distance=0,my_cha=0;

unsigned int Run_LastPost_1=0;  /*左轮上次提交数值*/
unsigned int Run_LastPost_2=0;  /*右轮上次提交数值*/

unsigned int Run_Ball_0=0;  /*复眼位置记录*/
unsigned int Run_Ball_1=0;  
unsigned int Run_Ball_2=0;  

unsigned int my_status=0;

unsigned int left_speed=0;
unsigned int right_speed=0;

unsigned int eye_ch_du=0;
unsigned int eye_ch_cmp=0;

unsigned int ball_distance=0;  /*球的远近*/  /*正前或正后方火焰值*/
unsigned int ball_light_jb=400;/*拨球亮度要求*/
///////////////////////////////////////////////////////////////
int ball_huoyan=100;
int eye_yuan_jin=300;


int my_EyeChMax()
{
	int ch=0;
	Run_Ball_2 = Run_Ball_1;
	Run_Ball_1 = Run_Ball_0;
	ch = EyeChMax();
	Run_Ball_0 = ch;
	return ch;
}

int time=0;
int key=0;

void Run(int sl,int sr)   //可设置功率,范围-100--100   可通过左下和右下按钮控制电机的停、转
{	
	//Run_LastPost_1=sl;
	//Run_LastPost_2=sr;
	//SetMoto(0,sl*power_speed);
	//SetMoto(1,sr*power_speed); 
	SetMoto(0,sl);
	SetMoto(1,sr); 
}

//倒车系列 
void Run_B(int sl,int sr)   //可设置功率,范围-100--100   可通过左下和右下按钮控制电机的停、转
{
	SetMoto(0,-sr*power_speed);
	SetMoto(1,-sl*power_speed); 
}

void findball_f()   /*正方向测球并标记**/
{    	
	if(eye_ch_all==1) //->1
	{gi_1=1;}
	else if((eye_ch_all>1)&&(eye_ch_all<5)) //->2,3,4
	{gi_1=2;}
	else if(eye_ch_all==5) //->5
	{gi_1=3;}
	else if(eye_ch_all==8) //->8
	{gi_1=4;}
	else if(eye_ch_all==3) //->9
	{gi_1=5;} 
	else if(eye_ch_all==10) //->3 
	{gi_1=6;} 
	else if((eye_ch_all==0)||(eye_ch_all==13)) //->11,12
	{gi_1=7;}
	else
    {gi_1=8;}  //->2,3,4   
}

void Run_back()
{
	my_status = 3;//防守 
	compass_1=Compass_Degree(); //获取指南针的方向 
	if((compass_1 <20)||(compass_1 >340)) //车头朝前 
 	{psdb=AI(1);//获取后红外距离
		if(psdb<100)Run(-90,-90);//离墙比较远 快速退回
		else if(psdb<160)Run(-40,-40);//离墙距离中等 退回速度变慢
		else if(psdb>220)Run(20,20);//离墙很近 往前蹭蹭 
		else Run(0,0);//离墙略近 停车 
	}
	else if((compass_1 >160)&&(compass_1 < 200))//车头朝后 
	{
		psdf=AI(0);//获取前红外距离 
		if(psdf<100)Run(90,90); //离墙比较远 快速退回
		else if(psdf<160)Run(40,40);//离墙距离中等 退回速度变慢
		else if(psdf>220)Run(-20,-20);//离墙很近 往前蹭蹭 
		else Run(0,0);//离墙略近 停车 
	}
   
	else if((compass_1 >= 20) && (compass_1 <  30)){Run(-16,16);}//右前方                
	else if((compass_1 >=330) && (compass_1 <=340)){Run(16,-16);}//左前方 
	else if((compass_1 >= 30) && (compass_1 <  60)){Run(-30,30);}// ...
	else if((compass_1 >=300) && (compass_1 < 330)){Run(30,-30);}   
	else if((compass_1 >= 60) && (compass_1 <  90)){Run(-50,50);}
	else if((compass_1 >=270) && (compass_1 < 300)){Run(50,-50);}   
     
	else if((compass_1 >= 90) && (compass_1 < 120)){Run(50,-50);}
	else if((compass_1 >=240) && (compass_1 < 270)){Run(-50,50);}   
	else if((compass_1 >=120) && (compass_1 < 150)){Run(30,-30);}
	else if((compass_1 >=210) && (compass_1 < 240)){Run(-30,30);}   
	else if((compass_1 >=150) && (compass_1 < 160)){Run(16,-16);}   
	else if((compass_1 > 200) && (compass_1 < 210)){Run(-16,16);}  //总之是根据方向倒车 
}


int a=0;

int my_fwjc_cmp(){
	compass_1=Compass_Degree();//获取指南针角度 
	if(compass_1 <31) gi_1 = 1; 
	else if (compass_1 <  61) gi_1 =  2; 	
	else if (compass_1 <  91) gi_1 =  3; 
	else if (compass_1 < 121) gi_1 =  4;
	else if (compass_1 < 151) gi_1 =  5; 			
	else if (compass_1 < 181) gi_1 =  6; 	   
	else if (compass_1 < 211) gi_1 =  7; 
	else if (compass_1 < 241) gi_1 =  8; 
 	else if (compass_1 < 271) gi_1 =  9; 
    else if (compass_1 < 301) gi_1 = 10; 	
	else if (compass_1 < 331) gi_1 = 11;
	else gi_1 = 12;
	
	return compass_1;
}

int sub_findfootball(){
	LCD_Clear_5110();
	printf_XY(0,0,"ftbl a 0.12");

	eye_ch_all=GetEyeMaxNum(2,0); //获取360上复眼方向
	eye_ch_num=GetSingleEye(eye_ch_all,0); //获取单个 
	if(AI(5) > ball_huoyan)return 0;//进攻 
	
	//分块控制
	//                                  近距离             远距离 
	if(eye_ch_num > eye_yuan_jin)     Run(0,100);   else Run(0,100);
	}else if(eye_ch_all==1){
		if(eye_ch_num > eye_yuan_jin) Run(30,100);  else Run(30,100);
	}else if(eye_ch_all==2){
		if(eye_ch_num > eye_yuan_jin) Run(60,100);  else Run(60,100);
	}else if(eye_ch_all==3){
		if(eye_ch_num > eye_yuan_jin) Run(100,100); else Run(100,100);
	}else if(eye_ch_all==4){
		if(eye_ch_num > eye_yuan_jin) Run(100,60);  else Run(100,60);
	}else if(eye_ch_all==5){
		if(eye_ch_num > eye_yuan_jin) Run(100,30);  else Run(100,30);
	}else if(eye_ch_all==6){
		if(eye_ch_num > eye_yuan_jin) Run(100,0);   else Run(100,0); 
	}else if(eye_ch_all==7){
		if(eye_ch_num > eye_yuan_jin) Run(100,-10); else Run(100,-10);  
	}else if(eye_ch_all==8){
		if(eye_ch_num > eye_yuan_jin) Run(100,-30); else Run(100,-30);
	}else if(eye_ch_all==9){
		if(eye_ch_num > eye_yuan_jin) Run(100,-60); else Run(100,-60); 
	}else if(eye_ch_all==10){
		if(eye_ch_num > eye_yuan_jin) Run(100,-100);else Run(100,-100); //左还是右？ 
	}else if(eye_ch_all==11){
		if(eye_ch_num > eye_yuan_jin) Run(-60,100); else Run(-60,100);
	}else if(eye_ch_all==12){
		if(eye_ch_num > eye_yuan_jin) Run(-30,100); else Run(-30,100); 
	}else if(eye_ch_all==13){
		if(eye_ch_num > eye_yuan_jin) Run(0,100);   else Run(0,100);  
	}

	return 0;
}
void attack_goal( )     /*正方向进攻*/
{
	my_status = 2;//进攻
	compass_1 = Compass_Degree();//指南针 
	ball_distance = AI(19);//三号复眼
	psdf = AI(0);//前红外  
	psdb = AI(1);//后 
	psdl = AI(2);//左 
	psdr = AI(3);//右 
	if(AI(19) > ball_light_jb && AI(5) > ball_huoyan) t=seconds(); else sub_findfootball(); //计时开始 
	psd_heng_cha = psdl - psdr;
	
	if(psdf_kaqiang < psdf){
		//前端卡墙
		if(psd_heng_cha > 0) Run(100,70); //左半部分
		else Run(70,100); //右 
	}
	
	if(psd_heng_cha > - psd_heng_middle && psd_heng_cha < psd_heng_middle){
		//中间部分 摆正进攻 
		if(psd_heng_cha > 0){
			//中间部分的左半部分
			compass_1 = Compass_Degree();//指南针
			if(compass_1 <= 25 || compass_1 >= 335) Run(90,100);
			else if (compass_1 <=  90) Run((100-compass_1),100);
			else if (compass_1 <= 180) Run(0,100);
			else if (compass_1 <= 270) Run(100,0);
			else if (compass_1 <= 360) Run(100,(100-compass_1));
			
		}else{
			//中间部分的右半部份 
			compass_1 = Compass_Degree();//指南针
			if(compass_1 <= 25 || compass_1 >= 335) Run(100,90);
			else if (compass_1 <=  90) Run(100,(100-compass_1));
			else if (compass_1 <= 180) Run(100,0);
			else if (compass_1 <= 270) Run(0,100);
			else if (compass_1 <= 360) Run((360-compass_1),100);//可能有问题 
		}
	}else if(psd_heng_cha > psd_heng_middle){
		//在左半部分 
		compass_1 = Compass_Degree();//指南针
		if(compass_1 >= 5 && compass_1 <= 45) Run(100,100);
		if(compass_1 <  5 || compass_1 > 330) Run(100,70);
		else Run(10,100);
	}
	else
	{
		//在右半部分 
		compass_1 = Compass_Degree();//指南针
		if(compass_1 <= 355 && compass_1 >= 315) Run(100,100);
		if(compass_1 >  355 || compass_1 <   30) Run(70,100);
		else Run(100,10);
	}
	
	if(AI(19) > ball_light_jb && AI(5) > ball_huoyan && t - seconds() > 15) 
	{
		Run(0,0);
		wait(0.5); 
		sub_findfootball();
	}
}


int sub_main(void)
{			
	LCD_Clear_5110();
	printf_XY(0,0,"ftbl a 0.01");

	my_status=1;//1-寻球 2-进攻 3-防守 
	while(1)
	{   
		LCD_Clear_5110();
		printf_XY(0,0,"ftbl a 0.02");
		while(EyeInMax() < ball){Run_back();}
		sub_findfootball();
		//while (1) if(Get_Button(0)==1) break;
	}
}




























