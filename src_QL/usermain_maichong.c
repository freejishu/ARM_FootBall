#include "RobotLib.h"



/*ʹ��˵��*/
/*int GetEyeMaxNum(int n,int m)*/ 
/*
ȡ�ø������ֵ���
���� n 0��ʾ����0   1��ʾ����1   2��ʾ���и���
���� m 0��ʾ��Ƶ��ģʽ  1��ʾ����ͨģʽ 
���� GetEyeMaxNum(0,0) ��ʾ�⸴��0��Ƶ��ģʽ

*/
/*int GetEyeMaxValue(int n,int m)*/
/*
ȡ�ø������ֵ
���� n 0��ʾ����0   1��ʾ����1   2��ʾ���и���
���� m 0��ʾ��Ƶ��ģʽ  1��ʾ����ͨģʽ 
���� GetEyeMaxValue(2,0) ��ʾ���������۵����ֵ��Ƶ��ģʽ  

*/

int GetSingleEye(int n,int m)
{
	int i,j;
  float t,temp_t;
  int AI_c;
  int AI_v[30];
	int AI_Max,AI_Min;
	int dis;
	int temp;
	//int last[13];
  AI_c=0;
  if(n>13) return 0;
  t=seconds();
  while(1)
  {
        temp_t =seconds();
        if(temp_t-t>0.00083)
        {
          break;
        }
        if(AI_c >=30)
        {
          break;
        }            
        AI_v[AI_c]=AI(16+n); //	QX    //AI_v[AI_c]=AI(14+n);     //////////////////////////
        AI_c++;
    }
    for(i=0;i<AI_c-1;i++)
      for(j=i+1;j<AI_c;j++)
      {
      	if(AI_v[i]>AI_v[j])
      	{
      		temp=AI_v[i];
      		AI_v[i]=AI_v[j];
      		AI_v[j]=temp;          		          		
      	}
      }
    AI_Min=AI_v[0];
    AI_Max=AI_v[0];        
    if(AI_c>0) AI_Max=AI_v[AI_c-1];
    if(m==0)
    {
    	dis=AI_Max-AI_Min;    
    }
	else
	{
		dis=AI_Max;    
	}
	//temp=last[n]*0.5;
	//if(dis < temp) dis = GetSingleEye(n,m);
	//last[n] = dis ;
    return dis*2;
}

int GetEyeMaxNum(int n,int m)
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
		tv[i]=GetSingleEye(i+7*n,m);
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
    return tid[num-1];
}

int GetEyeMaxValue(int n,int m)
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
		tv[i]=GetSingleEye(i+7*n,m);
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
    return tv[num-1];
}

////////////////////////////////////////////////////////////////////////

int s_GetSingleEye(int n,int m)
{
	int i,j;
    //float t,temp_t;
    int AI_c;
    int AI_v[30];
	int AI_Max,AI_Min;
	int dis;
	int temp;

	int i_s=0;

    AI_c=0;
    if(n>13) return 0;
    //t=seconds();
    for(i_s=0;i_s<10;i_s++)//while(1)
    {
        //temp_t =seconds();
        //if(temp_t-t>0.001)
        //{
        //  break;
        //}
        if(AI_c >=30)
        {
          break;
        }            
        AI_v[AI_c]=AI(16+n); //	QX    //AI_v[AI_c]=AI(14+n);     //////////////////////////
        AI_c++;
    }
    for(i=0;i<AI_c-1;i++)
      for(j=i+1;j<AI_c;j++)
      {
      	if(AI_v[i]>AI_v[j])
      	{
      		temp=AI_v[i];
      		AI_v[i]=AI_v[j];
      		AI_v[j]=temp;          		          		
      	}
      }
    AI_Min=AI_v[0];
    AI_Max=AI_v[0];        
    if(AI_c>0) AI_Max=AI_v[AI_c-1];
    if(m==0)
    {
    	dis=AI_Max-AI_Min;    
    }
	else
	{
		dis=AI_Max;    
	}
    return dis;
}

int s_GetEyeMaxNum(int n,int m)
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
    return tid[num-1];
}

int s_GetEyeMaxValue(int n,int m)
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
    return tv[num-1];
}





