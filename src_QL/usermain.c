//#include "RobotLib.h"
#include "usermain.h"

int btn_1=1280;
int MOTO_Dir=0;
int MOTO_val=0;
int i=0,j=0;
char ch[3];
//int i=345;
int main_a(void)   //int sub_main(void)   //void main()
{
    
	/* //????????
	while(1)
	{
		if(Get_Button(0)==1){btn_1=0X0000; SetLED(1);}
		else if(Get_Button(1)==1){btn_1=0X0001; SetLED(1);}
		else if(Get_Button(2)==1){btn_1=0X0002; SetLED(1);}
		else if(Get_Button(3)==1){btn_1=0X0003; SetLED(1);}
		else {btn_1=0X0008;SetLED(0);}
		SCI_Send(0, btn_1 ); 
	}
	*/
	
	
	/*  //LCD5110??
	//LCD_WriteEnglishSring(2,0,"wWW@163.COM,qq:38757291   666888");
	//LCD_WriteEnglishStr("wWW@163.COM");
	//LcdHanzi(8,3,"????");
	//DrawLine(0,0,40,20);
	//LCD_WriteEnglish('C');
	printf("%d,%f,%d,%d,%d\n%d,%d",btn_1,0.0056898998,335,668908,1000988,123,989);
	*/
	float t; 


	begin: 
	resettime();
	while(1)
	{
		/*
		EyeInMax();
    	EyeChMax();
    	EyeInMaxEx(EYE_0);
    	EyeChMaxEx(EYE_0);
		*/
		LCD_Clear_5110();
		printf_XY(0,1,"EYE_CH=%d",EyeChMax());
		printf_XY(0,2,"EYE_IN=%d",EyeInMax());
		printf_XY(0,3,"AI01=%d",AI(0));   printf_XY(60,3,"%d",AI(1));
		printf_XY(0,4,"AI23=%d",AI(2));   printf_XY(60,4,"%d",AI(3));
		printf_XY(0,5,"COMP=%d",Compass_Degree()); 
		wait(0.1);

		if(Get_Button(0)==1) 
		{
			
			wait(0.2);
			break;
		}
	}

	// motor ??
	resettime();
	LCD_Clear_5110();
	printf("      MOTOR");

	t=seconds();
	while(Get_Button(0)==0)
	{	 		
		wait(0.2);
		for(j=0;j<4 && Get_Button(0)==0;j++)
		{
			for(i=0;i<400&& Get_Button(0)==0;i++)
			{
				if(MOTO_Dir == 0)	
				{
					MOTO_val++;
					wait(0.01);
					if(MOTO_val==100)
					{
						MOTO_Dir = 1;	
					}
				}								
				else if(MOTO_Dir == 1)	
				{
					MOTO_val--;
					wait(0.01);
					if(MOTO_val==-100)
					{
						MOTO_Dir = 0;	
					}
				}										
				
				//LCD_Clear_5110();
				//printf("      MOTOR");
				printf_XY(0,3,"MOT:%d  sp:%d ",j,MOTO_val);
				
				//for(i=0;i<4;i++)
				//{
					SetMoto(j,MOTO_val);		
				//}								
			}
		}									
		
	}
	stop();
	while(Get_Button(0)==1);
	wait(0.05);
	
	// EYE_AI ??
	resettime();
	while(1)
	{
		//SetMoto(0,100);
		//SetMoto(1,-50);
		//LCD_SetXY(0,0);
		LCD_Clear_5110();
		//printf("EYE_AI=%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",AI(16),AI(17),AI(18),AI(19),AI(20),AI(21),AI(22),AI(23),AI(24),AI(25),AI(26),AI(27),AI(28),AI(29));
		printf_XY(30,0,"EYE0");
		printf_XY(0,1,"%d",AI(16));    printf_XY(22,1,"%d",AI(17));   printf_XY(44,1,"%d",AI(18));   printf_XY(66,1,"%d",AI(19));
		printf_XY(0,2,"%d",AI(20));    printf_XY(22,2,"%d",AI(21));   printf_XY(44,2,"%d",AI(22));   
		printf_XY(30,3,"EYE1");
		printf_XY(0,4,"%d",AI(23));    printf_XY(22,4,"%d",AI(24));   printf_XY(44,4,"%d",AI(25));   printf_XY(66,4,"%d",AI(26));
		printf_XY(0,5,"%d",AI(27));    printf_XY(22,5,"%d",AI(28));   printf_XY(44,5,"%d",AI(29));
		wait(0.2);
		//if(seconds()>2.0)break;
		if(Get_Button(0)==1) 
		{
			
			wait(0.2);
			break;
		}
	}

	
	// EYE_AI ??
	resettime();
	while(1)
	{
		//SetMoto(0,100);
		//SetMoto(1,-50);
		//LCD_SetXY(0,0);
		LCD_Clear_5110();
		//printf("EYE_AI=%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",AI(16),AI(17),AI(18),AI(19),AI(20),AI(21),AI(22),AI(23),AI(24),AI(25),AI(26),AI(27),AI(28),AI(29));
		printf_XY(30,0,"EYE0-MC");
		printf_XY(0,1,"%d",GetSingleEye(0,0));    printf_XY(22,1,"%d",GetSingleEye(1,0));   printf_XY(44,1,"%d",GetSingleEye(2,0));   printf_XY(66,1,"%d",GetSingleEye(3,0));
		printf_XY(0,2,"%d",GetSingleEye(4,0));    printf_XY(22,2,"%d",GetSingleEye(5,0));   printf_XY(44,2,"%d",GetSingleEye(6,0));   
		printf_XY(30,3,"EYE1-MC");
		printf_XY(0,4,"%d",GetSingleEye(7,0));    printf_XY(22,4,"%d",GetSingleEye(8,0));   printf_XY(44,4,"%d",GetSingleEye(9,0));   printf_XY(66,4,"%d",GetSingleEye(10,0));
		printf_XY(0,5,"%d",GetSingleEye(11,0));    printf_XY(22,5,"%d",GetSingleEye(12,0));   printf_XY(44,5,"%d",GetSingleEye(13,0));
		wait(0.2);
		//if(seconds()>2.0)break;
		if(Get_Button(0)==1) 
		{		
			wait(0.2);
			break;
		}
	}

	// AI ??
	resettime();
	while(1)
	{
		//LCD_SetXY(0,0);
		LCD_Clear_5110();
		//printf("AI=%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",AI(0),AI(1),AI(2),AI(3),AI(4),AI(5),AI(6),AI(7),AI(8),AI(9),AI(10),AI(11),AI(12),AI(13),AI(14),AI(15));
			printf_XY(30,0,"AI");   printf_XY(60,0,"%d",AI(31));
		printf_XY(0,1,"%d",AI(0));    printf_XY(22,1,"%d",AI(1));   printf_XY(44,1,"%d",AI(2));   printf_XY(66,1,"%d",AI(3));
		printf_XY(0,2,"%d",AI(4));    printf_XY(22,2,"%d",AI(5));   printf_XY(44,2,"%d",AI(6));   printf_XY(66,2,"%d",AI(7));
		
		printf_XY(0,3,"%d",AI(8));    printf_XY(22,3,"%d",AI(9));   printf_XY(44,3,"%d",AI(10));   printf_XY(66,3,"%d",AI(11));
		printf_XY(0,4,"%d",AI(12));    printf_XY(22,4,"%d",AI(13));   printf_XY(44,4,"%d",AI(14));	 printf_XY(66,4,"%d",AI(15));

		printf_XY(0,5,"%d",AI(30));   printf_XY(30,5,"TEP%f",GetChipTemp()); printf_XY(78,5,"     ");
		wait(0.1);
		//if(seconds()>2.0)break;
		if(Get_Button(0)==1) 
		{
			
			wait(0.2);
			break;
		}
	}
	


	// DI ??
	resettime();
	while(1)
	{
		//LCD_SetXY(0,0);
		LCD_Clear_5110();
		printf("      DI=     %d,%d,%d,%d,      %d,%d,%d,%d,      %d,%d,%d,%d,      %d,%d,%d,%d",DI(0),DI(1),DI(2),DI(3),DI(4),DI(5),DI(6),DI(7),DI(8),DI(9),DI(10),DI(11),DI(12),DI(13),DI(14),DI(15));
		wait(0.01);
		//if(seconds()>50.0)break;
		if(Get_Button(0)==1) 
		{
			wait(0.2);
			break;
		}
	}

	// DO ??
	resettime();
	LCD_Clear_5110();
	printf("      DO");
	while(1)
	{	
		LCD_Clear_5110();
		printf("      DO");
		printf_XY(0,1,"DO  ON ");   		
		t=seconds();		
		while(seconds()-t<0.5&&Get_Button(0)==0)
		{
			{
    			int i_0;for(i_0=0;i_0<=15 ;i_0++)
    			{
					SetDO(i_0,1);	
    			}
			}				
			
			//SetDO(0,1);SetDO(1,1);SetDO(2,1);SetDO(3,1);SetDO(4,1);SetDO(5,1);SetDO(6,1);SetDO(7,1);
			//SetDO(8,1);SetDO(9,1);SetDO(10,1);SetDO(11,1);SetDO(12,1);SetDO(13,1);SetDO(14,1);SetDO(15,1);  			
		}
		LCD_Clear_5110();
		printf("      DO");
		printf_XY(0,1,"DO  OFF"); 
		t=seconds();
		while(seconds()-t<0.5&&Get_Button(0)==0)
		{
			{
    			int i_0;for(i_0=0;i_0<=15 ;i_0++)
    			{
					SetDO(i_0,0);	
    			}
			}

			//SetDO(0,0);SetDO(1,0);SetDO(2,0);SetDO(3,0);SetDO(4,0);SetDO(5,0);SetDO(6,0);SetDO(7,0);
			//SetDO(8,0);SetDO(9,0);SetDO(10,0);SetDO(11,0);SetDO(12,0);SetDO(13,0);SetDO(14,0);SetDO(15,0);			
		}		
		
		//if(seconds()>2.0)break;
		if(Get_Button(0)==1) 
		{
			wait(0.2);
			break;
		}
	}
	/*
	resettime();
	LCD_Clear_5110();
	printf("      FLASH TEST");
	
	for(i=0;i<100;i++){

	}
	for(i=0;i<100;i++){
		printf("%d",FLASH_Read(i));
	}
	while(1){
		if(Get_Button(0)==1) 
		{
			break;
		}
	}
	
	*/

	// serv moto ??
	resettime();
	LCD_Clear_5110();
	printf("      SERVO MOT");
	while(1)
	{
		{
    		int i_0;for(i_0=0;i_0<=15 ;i_0++)
    		{
				SetServo(i_0,30,100);	//????????
    		}
		}
		/*
		SetServo(0, 30, 100);  //????????  
		SetServo(1, 30, 100);SetServo(2, 30, 100);SetServo(3, 30, 100);SetServo(4, 30, 100);SetServo(5, 30, 100);SetServo(6, 30, 100);
		SetServo(7, 30, 100);SetServo(8, 30, 100);SetServo(9, 30, 100);SetServo(10, 30, 100);SetServo(11, 30, 100);SetServo(12, 30, 100);
		SetServo(13, 30, 100);SetServo(14, 30, 100);SetServo(15, 30, 100);
		*/
			LCD_Clear_5110();
			printf_XY(0,0,"ALL SERV MOT ");
			printf_XY(0,2,"degree  30");
			printf_XY(0,4," speed 100");
		t=seconds(); 
		while(seconds()-t<1.5&&Get_Button(0)==0)
		{
		}

		{
    		int i_0;for(i_0=0;i_0<=15 ;i_0++)
    		{
				SetServo(i_0,160,60);	//????????
    		}
		}
		/*
		SetServo(0, 160, 60);  //????????
		SetServo(1, 160, 60);SetServo(2, 160, 60);SetServo(3, 160, 60);SetServo(4, 160, 60);SetServo(5, 160, 60);SetServo(6, 160, 60);
		SetServo(7, 160, 60);SetServo(8, 160, 60);SetServo(9, 160, 60);SetServo(10, 160, 60);SetServo(11, 160, 60);SetServo(12, 160, 60);
		SetServo(13, 160, 60);SetServo(14, 160, 60);SetServo(15, 160, 60);
		*/
			LCD_Clear_5110();
			printf_XY(0,0,"ALL SERV MOT ");
			printf_XY(0,2,"degree 160");
			printf_XY(0,4," speed  60");	   
		t=seconds(); 
		while(seconds()-t<3.2&&Get_Button(0)==0)
		{	
		}
		//if(seconds()>2.0)break;
		if(Get_Button(0)==1) 
		{
			wait(0.2);
			break;
		}
	}

	// ????
	resettime();
	while(1)
	{
		//SCI_Send(0, 10 );
		//SCI_Send(1, 11 );
		//SCI_Send(2, 12 ); 
		
		//LCD_SetXY(0,0);	  	 
    	LCD_Clear_5110();
		printf("UART0=%d",SCI_Receive(0));
		LCD_SetXY(0,1);
		printf("UART1=%d",SCI_Receive(1));
		LCD_SetXY(0,2);
		printf("UART2=%d",SCI_Receive(2));
		wait(0.1);

		//if(seconds()>60.0)break;
		if(Get_Button(0)==1) 
		{
			wait(0.2);
			break;
		}
	}


	LCD_Clear_5110();
	printf("   TEST OVER");

	while(1)
	{
		if(Get_Button(0)==1) 
		{
			wait(0.2);
			goto begin; 
			//break;
		}
	}
	//while(1)
	//{ 		 	
	//} 
}
