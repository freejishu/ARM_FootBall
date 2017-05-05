#define irl     AI(0)           
#define irf     AI(1)
#define irr     AI(2)
#define irb     AI(3)


#include "RobotLib.h"
#include "key_selection.h"


int sum_key=0; 		 
int num_1=0,num_2=0,test_num=0; 
int HTZ_Ch,HTZ_In;
			
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



int test_main(void)
{
	Printf("Motor 0 -> Run(50,-30);");
	SetMoto(0,50);
	SetMoto(1,-30); 
	while(1){
		wait(0.1);
		if (Get_Button(0)==1) break; 
	}
	return 0;
}

				
int main_key_selection(void)
{	

	if(FLASH_Read(50)<18)
		sum_key=FLASH_Read(50);
	
	LCD_Clear_5110();
	printf_XY(2,0,"QX_ROBOT I");    printf_XY(76,0,"%d",sum_key);
	
	printf_XY(6,1,"0 ftbl");      printf_XY(48,1,"5 ...");
	printf_XY(6,2,"1 jsts");      printf_XY(48,2,"6 ...");
	printf_XY(6,3,"2 TsMC");       printf_XY(48,3,"7 ...");
	printf_XY(6,4,"3 TsMe");       printf_XY(48,4,"8 rtc");
	printf_XY(6,5,"4 T100");       printf_XY(48,5,"9 test");

	//printf_XY(0,1,">");

	{
    	int i_0;for(i_0=1;i_0<=5 ;i_0++)
    	{
			printf_XY(0,i_0," ");
			printf_XY(42,i_0," ");	
    	}
	}		 			
			
	if(sum_key<=4) 	 printf_XY(0,sum_key+1,">");
	else  if(sum_key>4) 	 printf_XY(42,sum_key-4,">");
			
	while(Get_Button(3)==0)
	{
		if(Get_Button(1)==1)	   //Õ˘¿Ô∞¥£®÷–£©
		{				
			if(sum_key<6)
				FLASH_Write(50,sum_key);
			

		}
		else if (Get_Button(2)==1)	  //Õ˘◊Û≤¶£®…œ£©
		{	
			wait(0.001); 			
			while(Get_Button(2)==1)
			{ 				
			}
			wait(0.001);

			if(sum_key<=8)	sum_key=sum_key++;
			else  sum_key=sum_key;

			//keyy=2;

			printf_XY(76,0,"%d",sum_key);

			{
    			int i_0;for(i_0=1;i_0<=5 ;i_0++)
    			{
					printf_XY(0,i_0," ");
					printf_XY(42,i_0," ");	
    			}
			}		 			
			
			if(sum_key<=4) 	 printf_XY(0,sum_key+1,">");
			else  if(sum_key>4) 	 printf_XY(42,sum_key-4,">");
			

		}
		else if (Get_Button(0)==1)		//Õ˘”“≤¶£®œ¬£©
		{					
			wait(0.001); 			
			while(Get_Button(0)==1)
			{					
			}
			wait(0.001);

			if(sum_key>=1)	sum_key=sum_key--;
			else  sum_key=sum_key;

			//keyy=1;

			printf_XY(76,0,"%d",sum_key);

			{
    			int i_0;for(i_0=1;i_0<=5 ;i_0++)
    			{
					printf_XY(0,i_0," ");
					printf_XY(42,i_0," ");	
    			}
			}		 			
		
			if(sum_key<=4) 	 printf_XY(0,sum_key+1,">");
			else  if(sum_key>4) 	 printf_XY(42,sum_key-4,">");
			

		}
		else
		{		 		
		}	  		
	}

	//Printf("sum_key=%d\n",sum_key);  

	if(sum_key==0)
	{
		//LCD_Clear_5110();
		//Printf("0 footbll");
		sub_main();//main_b();
	}

	else if(sum_key==1)
	{
		int i = 0;
		float t_1 = 0 ,t_2 = 0;
		t_1=seconds();
		for(i=0;i<10000;i++){
		t_2 = i/3;
		
}LCD_Clear_5110();
		printf_XY(0,0,"1 Printf_test\n");
		printf_XY(0,1,"*******");
		printf_XY(0,2,"i=%d",i);
		printf_XY(0,3,"i/3=%f",t_2);
		printf_XY(0,4,"usetime=%f",seconds()-t_1);
		printf_XY(0,5,"*******");
		
	}
	else if(sum_key==2)
	{
		

		while(1){
    LCD_Clear_5110();  
    //Printf("ch=%d,ch=%d,"MY_EyeChMax()); 
		printf_XY(0,1,"Tch=%d",GetEyeMaxNum(2,0));    printf_XY(42,1,"Tin=%d",GetEyeMaxValue(2,0));
		printf_XY(0,2,"10C=%d",s_GetEyeMaxNum(2,0));  printf_XY(42,2,"10I=%d",s_GetEyeMaxValue(2,0));
		printf_XY(0,3,"ch=%d",GetEyeMaxNum(2,1));     printf_XY(42,3,"in=%d",GetEyeMaxValue(2,1));
    printf_XY(0,4,"HCh=%d",HTZ_Ch);               printf_XY(42,4,"HIn=%d",HTZ_In);
    printf_XY(0,5,"T10=%d",GetSingleEye(10,0));   printf_XY(44,5,"10C=%d",GetSingleEye(10,1));
		printf_XY(0,0,"Test MaiChong"); 
		wait(0.1);
		}
		
	}

	else if(sum_key==3)
	{
		
		int speed_left=0,speed_right=0;
		int tag_left=1,tag_right=1;//1+ 2-
		LCD_Clear_5110();
		printf_XY(0,0,"Mec Test");
		printf_XY(0,1,"********************");
		printf_XY(0,2,"ls=%d",speed_left);
		printf_XY(0,3,"rs=%d",speed_right);
		printf_XY(0,4,"********************");
		SetMoto(0,0);
		SetMoto(1,0); 
		while(1){ 
			if(Get_Button(0)==1) {
				//Õ˘”“->◊Û¬÷
				if(tag_left==1){
					speed_left=speed_left+10;
					if(speed_left==110){
						speed_left=90;tag_left=2;
					}
				}else{
					speed_left=speed_left-10;
					if(speed_left==-100){
						speed_left=-90;tag_left=1;
					}
				}
				SetMoto(0,speed_left);
				LCD_Clear_5110();
				printf_XY(0,0,"Mec Test");
				printf_XY(0,1,"********************");
				printf_XY(0,2,"ls=%d",speed_left);
				printf_XY(0,3,"rs=%d",speed_right);
				printf_XY(0,4,"********************");
				wait(0.5);
			}
			if(Get_Button(2)==1) {
				//Õ˘◊Û->”“¬÷
				if(tag_right==1){
					speed_right=speed_right+10;
					if(speed_right==110){
						speed_right=90;tag_right=2;
					}
				}else{
					speed_right=speed_right-10;
					if(speed_right==-110){
						speed_right=-90;tag_right=1;
					}
				}
				SetMoto(1,speed_right);
				LCD_Clear_5110();
				printf_XY(0,0,"Mec Test");
				printf_XY(0,1,"********************");
				printf_XY(0,2,"ls=%d",speed_left);
				printf_XY(0,3,"rs=%d",speed_right);
				printf_XY(0,4,"********************");
				wait(0.5);
			}
				wait(0.03);
		}
		
		//printf_XY(0,2,"left speed=100");
		//printf_XY(0,3,"right speed=100");
		//while(1){
		
		//}
		
		
		
	}
	else if(sum_key==4)
	{
		LCD_Clear_5110();
		Printf("4 ...");
		while(1){
			SetMoto(0,100);
			SetMoto(1,100);
			wait(0.02);
		}
	}
	else if(sum_key==5)
	{
		LCD_Clear_5110();
		Printf("5 ...");
		while(1){
			SetMoto(0,100);
			SetMoto(1,100);
			wait(0.02);
		}
	}
	else if(sum_key==6)
	{
		LCD_Clear_5110();
		Printf("6 ...");
	}
	else if(sum_key==7)
	{
		LCD_Clear_5110();
		Printf("7 ...");
	}
	else if(sum_key==8)
	{
		LCD_Clear_5110();
		Printf("8 rtc");
		main_c();
	}
	else if(sum_key==9)
	{
		LCD_Clear_5110();
		Printf("9 test");
		main_a();
	}
	/****************************/

	while (1);
} 
