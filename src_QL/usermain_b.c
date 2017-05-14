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
/* 
��������ǰ���ǰ�����鸴�۰�д�ģ�7+7=14·��

��������Ӧ�ĸ����Ǵ�AI(16)��ʼ

��Ϊ���ǵĿ�������AI(0)~AI(15)��Ԥ������������ģ�⴫�����õġ�
���۽ӿ��õ�AI(16)��ʼ��AI(29).

ǰ�����鸴������7+7=14·ģ��ڣ�AI(16)��AI(29).
*/ 

#include "RobotLib.h"
unsigned int gi_1=0;  /*CMPָʾ����ڻ����˵ķ�λ���*/
unsigned int eye_ch_all=0; /*����ͨ��*/

unsigned int psdf=0,psdb=0,psdl=0,psdr=0;  /*ǰ�������Һ�����*/

unsigned int back_psd_distance=0;  /*�������B*/
unsigned int psd_heng_cha=0; 
unsigned int psd_heng_middle=200;

int compass_1=0;    //unsigned int compass_1=0;  /*ָ����*/

float power_speed=1.0,t;
unsigned int ball=20;/*��û����*/
unsigned int ball_huoyan=0; //���� ���� 
unsigned int psdf_kaqiang=550; //���� ���� 
unsigned int eye_ch_num=0;//, eye_ch_left=0, eye_ch_right=0 ,gi_left_right=0;
//unsigned int eye_ch_max_s=0, tag_ball_distance=0,my_cha=0;

unsigned int Run_LastPost_1=0;  /*�����ϴ��ύ��ֵ*/
unsigned int Run_LastPost_2=0;  /*�����ϴ��ύ��ֵ*/

//unsigned int Run_Ball_0=0;  /*����λ�ü�¼*/
//unsigned int Run_Ball_1=0;  
//unsigned int Run_Ball_2=0;  

unsigned int my_status=0;

//unsigned int left_speed=0;
//unsigned int right_speed=0;

unsigned int eye_ch_du=0;
unsigned int eye_ch_cmp=0;

unsigned int ball_distance=0;  /*���Զ��*/  /*��ǰ�����󷽻���ֵ*/
unsigned int ball_light_jb=400;/*��������Ҫ��*/
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



void Run(int sl,int sr)   //�����ù���,��Χ-100--100   ��ͨ�����º����°�ť���Ƶ����ͣ��ת
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

	//eye_ch_all=GetEyeMaxNum(2,0); //��ȡ360�ϸ��۷���
	eye_ch_all= EyeChMax();
	eye_ch_num=GetSingleEye(eye_ch_all,0); //��ȡ���� 
	//LCD_Clear_5110();
	//printf_XY(0,1,"EYE_CH=%d",eye_ch_all);
	//printf_XY(0,2,"EYE_IN=%d",eye_ch_num);
	 
	//if(AI(5) > ball_huoyan) return 0;//���� 
	
	//�ֿ����
	//                                  ������             Զ���� 
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
	//my_status=1;//1-Ѱ�� 2-���� 3-���� 
	while(1)
	{   
		//while(EyeInMax() < ball){Run_back();}
		sub_findfootball();
		wait(0.02);
		//while (1) if(Get_Button(0)==1) break;
	}
}




























