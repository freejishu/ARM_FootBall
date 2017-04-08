#define irl     AI(0)           
#define irf     AI(1)
#define irr     AI(2)
#define irb     AI(3)


#include "RobotLib.h"
#include "key_selection.h"


int sum_key=0; 		 
int num_1=0,num_2=0,test_num=0; 		
			
			


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
	printf_XY(6,2,"1 jsts");       printf_XY(48,2,"6 ...");
	printf_XY(6,3,"2 ...");       printf_XY(48,3,"7 ...");
	printf_XY(6,4,"3 ...");       printf_XY(48,4,"8 rtc");
	printf_XY(6,5,"4 ...");       printf_XY(48,5,"9 test");

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
		if(Get_Button(1)==1)	   //往里按（中）
		{				
			if(sum_key<6)
				FLASH_Write(50,sum_key);
			

		}
		else if (Get_Button(2)==1)	  //往左拨（上）
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
		else if (Get_Button(0)==1)		//往右拨（下）
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
		LCD_Clear_5110();
		while(1){Printf_XY(0,0,"irl=%d",irl);wait(0.05);}
		
	}

	else if(sum_key==3)
	{
		LCD_Clear_5110();
		Printf("3 ...");
	}
	else if(sum_key==4)
	{
		LCD_Clear_5110();
		Printf("4 ...");
	}
	else if(sum_key==5)
	{
		LCD_Clear_5110();
		Printf("5 ...");
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
