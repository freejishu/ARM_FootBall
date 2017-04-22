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
unsigned int ball=80;/*��û����*/
unsigned int ball_huoyan=0; //���� ���� 
unsigned int psdf_kaqiang=550; //���� ���� 
unsigned int eye_ch_num=0, eye_ch_left=0, eye_ch_right=0 ,gi_left_right=0;
unsigned int eye_ch_max_s=0, tag_ball_distance=0,my_cha=0;

unsigned int Run_LastPost_1=0;  /*�����ϴ��ύ��ֵ*/
unsigned int Run_LastPost_2=0;  /*�����ϴ��ύ��ֵ*/

unsigned int Run_Ball_0=0;  /*����λ�ü�¼*/
unsigned int Run_Ball_1=0;  
unsigned int Run_Ball_2=0;  

unsigned int my_status=0;

unsigned int left_speed=0;
unsigned int right_speed=0;

unsigned int eye_ch_du=0;
unsigned int eye_ch_cmp=0;

unsigned int ball_distance=0;  /*���Զ��*/  /*��ǰ�����󷽻���ֵ*/
unsigned int ball_light_jb=400;/*��������Ҫ��*/
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

void Run(int sl,int sr)   //�����ù���,��Χ-100--100   ��ͨ�����º����°�ť���Ƶ����ͣ��ת
{	
	//Run_LastPost_1=sl;
	//Run_LastPost_2=sr;
	//SetMoto(0,sl*power_speed);
	//SetMoto(1,sr*power_speed); 
	SetMoto(0,sl);
	SetMoto(1,sr); 
}

//����ϵ�� 
void Run_B(int sl,int sr)   //�����ù���,��Χ-100--100   ��ͨ�����º����°�ť���Ƶ����ͣ��ת
{
	SetMoto(0,-sr*power_speed);
	SetMoto(1,-sl*power_speed); 
}

void findball_f()   /*��������򲢱��**/
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
	my_status = 3;//���� 
	compass_1=Compass_Degree(); //��ȡָ����ķ��� 
	if((compass_1 <20)||(compass_1 >340)) //��ͷ��ǰ 
 	{psdb=AI(1);//��ȡ��������
		if(psdb<100)Run(-90,-90);//��ǽ�Ƚ�Զ �����˻�
		else if(psdb<160)Run(-40,-40);//��ǽ�����е� �˻��ٶȱ���
		else if(psdb>220)Run(20,20);//��ǽ�ܽ� ��ǰ��� 
		else Run(0,0);//��ǽ�Խ� ͣ�� 
	}
	else if((compass_1 >160)&&(compass_1 < 200))//��ͷ���� 
	{
		psdf=AI(0);//��ȡǰ������� 
		if(psdf<100)Run(90,90); //��ǽ�Ƚ�Զ �����˻�
		else if(psdf<160)Run(40,40);//��ǽ�����е� �˻��ٶȱ���
		else if(psdf>220)Run(-20,-20);//��ǽ�ܽ� ��ǰ��� 
		else Run(0,0);//��ǽ�Խ� ͣ�� 
	}
   
	else if((compass_1 >= 20) && (compass_1 <  30)){Run(-16,16);}//��ǰ��                
	else if((compass_1 >=330) && (compass_1 <=340)){Run(16,-16);}//��ǰ�� 
	else if((compass_1 >= 30) && (compass_1 <  60)){Run(-30,30);}// ...
	else if((compass_1 >=300) && (compass_1 < 330)){Run(30,-30);}   
	else if((compass_1 >= 60) && (compass_1 <  90)){Run(-50,50);}
	else if((compass_1 >=270) && (compass_1 < 300)){Run(50,-50);}   
     
	else if((compass_1 >= 90) && (compass_1 < 120)){Run(50,-50);}
	else if((compass_1 >=240) && (compass_1 < 270)){Run(-50,50);}   
	else if((compass_1 >=120) && (compass_1 < 150)){Run(30,-30);}
	else if((compass_1 >=210) && (compass_1 < 240)){Run(-30,30);}   
	else if((compass_1 >=150) && (compass_1 < 160)){Run(16,-16);}   
	else if((compass_1 > 200) && (compass_1 < 210)){Run(-16,16);}  //��֮�Ǹ��ݷ��򵹳� 
}


int a=0;

int my_fwjc_cmp(){
	compass_1=Compass_Degree();//��ȡָ����Ƕ� 
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

	eye_ch_all=GetEyeMaxNum(2,0); //��ȡ360�ϸ��۷���
	eye_ch_num=GetSingleEye(eye_ch_all,0); //��ȡ���� 
	if(AI(5) > ball_huoyan)return 0;//���� 
	
	//�ֿ����
	//                                  ������             Զ���� 
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
		if(eye_ch_num > eye_yuan_jin) Run(100,-100);else Run(100,-100); //�����ң� 
	}else if(eye_ch_all==11){
		if(eye_ch_num > eye_yuan_jin) Run(-60,100); else Run(-60,100);
	}else if(eye_ch_all==12){
		if(eye_ch_num > eye_yuan_jin) Run(-30,100); else Run(-30,100); 
	}else if(eye_ch_all==13){
		if(eye_ch_num > eye_yuan_jin) Run(0,100);   else Run(0,100);  
	}

	return 0;
}
void attack_goal( )     /*���������*/
{
	my_status = 2;//����
	compass_1 = Compass_Degree();//ָ���� 
	ball_distance = AI(19);//���Ÿ���
	psdf = AI(0);//ǰ����  
	psdb = AI(1);//�� 
	psdl = AI(2);//�� 
	psdr = AI(3);//�� 
	if(AI(19) > ball_light_jb && AI(5) > ball_huoyan) t=seconds(); else sub_findfootball(); //��ʱ��ʼ 
	psd_heng_cha = psdl - psdr;
	
	if(psdf_kaqiang < psdf){
		//ǰ�˿�ǽ
		if(psd_heng_cha > 0) Run(100,70); //��벿��
		else Run(70,100); //�� 
	}
	
	if(psd_heng_cha > - psd_heng_middle && psd_heng_cha < psd_heng_middle){
		//�м䲿�� �������� 
		if(psd_heng_cha > 0){
			//�м䲿�ֵ���벿��
			compass_1 = Compass_Degree();//ָ����
			if(compass_1 <= 25 || compass_1 >= 335) Run(90,100);
			else if (compass_1 <=  90) Run((100-compass_1),100);
			else if (compass_1 <= 180) Run(0,100);
			else if (compass_1 <= 270) Run(100,0);
			else if (compass_1 <= 360) Run(100,(100-compass_1));
			
		}else{
			//�м䲿�ֵ��Ұ벿�� 
			compass_1 = Compass_Degree();//ָ����
			if(compass_1 <= 25 || compass_1 >= 335) Run(100,90);
			else if (compass_1 <=  90) Run(100,(100-compass_1));
			else if (compass_1 <= 180) Run(100,0);
			else if (compass_1 <= 270) Run(0,100);
			else if (compass_1 <= 360) Run((360-compass_1),100);//���������� 
		}
	}else if(psd_heng_cha > psd_heng_middle){
		//����벿�� 
		compass_1 = Compass_Degree();//ָ����
		if(compass_1 >= 5 && compass_1 <= 45) Run(100,100);
		if(compass_1 <  5 || compass_1 > 330) Run(100,70);
		else Run(10,100);
	}
	else
	{
		//���Ұ벿�� 
		compass_1 = Compass_Degree();//ָ����
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

	my_status=1;//1-Ѱ�� 2-���� 3-���� 
	while(1)
	{   
		LCD_Clear_5110();
		printf_XY(0,0,"ftbl a 0.02");
		while(EyeInMax() < ball){Run_back();}
		sub_findfootball();
		//while (1) if(Get_Button(0)==1) break;
	}
}




























