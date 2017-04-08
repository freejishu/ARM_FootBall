#include"stm32f10x_conf.h" 
#include"LCD5110_Driver.h"
#include"LCD5110_API.h"
//#include"main_5110.h" 	   /////////////

GPIO_InitTypeDef GPIO_InitStructure;//����ṹ�����GPIO_InitStructure
void Syste_Init(void)
{	
	
	
	/***WHM*****************************************/
	RCC_HSEConfig(RCC_HSE_ON); //�����ⲿ����ʱ��
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOD,ENABLE );//����GPIODʱ��
	/***WHM*****************************************/ 
	
	/*
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;//ѡ��4��5��
    //GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//���
    //GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//ʱ��Ϊ2M
    GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;//ѡ��4��5��7��
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//���
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//ʱ��Ϊ2M
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	*/
	//GPIO-ģ��SPI==================ģ��SPI����Ӧ�˿�����================
	GPIO_InitStructure.GPIO_Pin = LCD_SCE | LCD_SDIN | LCD_SCLK;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
	/***WHM*****************************************/ 
	GPIO_Init(GPIOD, &GPIO_InitStructure); //��GPIOD�Ĳ�ͬ�ܽŽ��г�ʼ������
	/***WHM*****************************************/ 
	GPIO_InitStructure.GPIO_Pin = LCD_RST | LCD_DC;			
	/***WHM*****************************************/
	GPIO_Init(GPIOD, &GPIO_InitStructure); //��GPIOD�Ĳ�ͬ�ܽŽ��г�ʼ������
	/***WHM*****************************************/
}

void main_5110(void)
{
	Syste_Init();
	
	LCD_Init();
	LCD_WriteDot(0,0,DOT_DRAW);
	LCD_WriteDot(83,0,DOT_DRAW);
	LCD_WriteDot(0,47,DOT_DRAW);
	LCD_WriteDot(83,47,DOT_DRAW);

	LCD_WriteEnglishSring(5,0,"wanghm35@163.COM,qq:38757291   888888");
	
	LcdHanzi(10,3,"��������");
	//LCD_WriteEnglish(' ');
	//LCD_WriteEnglish('a');
	//LCD_WriteEnglish('b');
	//LCD_WriteEnglish('c');

	
	DrawLine(0,0,40,20);
	//CommitBuffer();
	
	while(1)
	{
	 	
	}

}



