#ifndef _LCD_API_H_
#define _LCD_API_H_

//==被外部调用的函数原型声明==

//画点函数，可以屏幕任意位置对点进行擦除、画点、取反操作
void LCD_WriteDot(unsigned char Dot_X,unsigned char Dot_Y,LCD_DotMode Mode);
//提交缓存函数，将缓存中的数据送入LCD的RAM
void CommitBuffer( void );
//画直线函数，可以根据给出的两个点画出直线
void DrawLine(unsigned char Xbegin,unsigned char Ybegin,unsigned char Xend,unsigned char Yend);
//void LCD_WriteEnlish(unsigned char EnlishChar);
void LCD_WriteEnglish(unsigned char EnlishChar);
/**whm*************/
void LCD_WriteEnglishStr(unsigned char *s);
/**whm****************/
void LCD_WriteEnglishSring(unsigned char X,unsigned char Y,char *s);

unsigned char LcdHanzi(unsigned char x,unsigned char y,const unsigned char *pCluster);

#endif

