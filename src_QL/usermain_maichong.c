#include "RobotLib.h"



/*使用说明*/
/*int GetEyeMaxNum(int n,int m)*/ 
/*
取得复眼最大值编号
参数 n 0表示复眼0   1表示复眼1   2表示所有复眼
参数 m 0表示测频闪模式  1表示测普通模式 
例如 GetEyeMaxNum(0,0) 表示测复眼0在频闪模式

*/
/*int GetEyeMaxValue(int n,int m)*/
/*
取得复眼最大值
参数 n 0表示复眼0   1表示复眼1   2表示所有复眼
参数 m 0表示测频闪模式  1表示测普通模式 
例如 GetEyeMaxValue(2,0) 表示测两个复眼的最大值在频闪模式  

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





