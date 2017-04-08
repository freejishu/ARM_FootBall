#ifndef _LCD_API_H_
#define _LCD_API_H_

//==���ⲿ���õĺ���ԭ������==

//���㺯����������Ļ����λ�öԵ���в��������㡢ȡ������
void LCD_WriteDot(unsigned char Dot_X,unsigned char Dot_Y,LCD_DotMode Mode);
//�ύ���溯�����������е���������LCD��RAM
void CommitBuffer( void );
//��ֱ�ߺ��������Ը��ݸ����������㻭��ֱ��
void DrawLine(unsigned char Xbegin,unsigned char Ybegin,unsigned char Xend,unsigned char Yend);
//void LCD_WriteEnlish(unsigned char EnlishChar);
void LCD_WriteEnglish(unsigned char EnlishChar);
/**whm*************/
void LCD_WriteEnglishStr(unsigned char *s);
/**whm****************/
void LCD_WriteEnglishSring(unsigned char X,unsigned char Y,char *s);

unsigned char LcdHanzi(unsigned char x,unsigned char y,const unsigned char *pCluster);

#endif

