/* 
File: subject design
Description: 火车票票务管理系统
Programmer: Liang Xikuang
Date: 2018/03/06
*/ 

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct traininfor
{
	int tnumber;//车次号
	int aprice;//硬座车票价格
	int bprice;//硬卧车票价格
	int cprice; //软卧车票价格
	int Alnumber;//生成硬座票量
	int Blnumber;//生成硬卧票量
	int Clnumber;//生成软卧票量
	struct traininfor *next;
};
typedef  struct traininfor node1,*pemp;

struct buyer
{
	char name[10];//购票人姓名
	char id[18]; //购票人身份证号 
	int Abnumber;//购买硬座张数 
	int Bbnumber;//购买硬卧张数
    int Cbnumber;//购买软卧张数
    struct buyer *next;
};
typedef struct buyer node2,*consumer;

void menu(pemp ,consumer ,int n);
void tickets(pemp ,int n);
void check(pemp ,consumer ,int n);
void buy(pemp ,consumer );

int main()
{
	int i=10;
	pemp trhead;
	consumer conhead;
	
	trhead=(pemp)malloc(sizeof(node1));
	conhead=(consumer)malloc(sizeof(node2));
	trhead->next=NULL;
	conhead->next=NULL;
	system("color 1b");
	//system("color 0A");
	menu(trhead,conhead,i);
	tickets(trhead,i);
	
	return 0;
}

void menu(pemp trhead,consumer conhead,int n)//菜单函数 
{
	int a;
	
	printf("\n\n\n\n\n                      ------------.o0目录0o.------------\n");
	printf("                       1,查询车票\n");
	printf("                       2,购买车票\n");
	printf("                       3,退订车票\n");
	printf("                       4,改签\n");
	printf("                       5,退出程序\n");
	printf("                       请输入选项序号：");
	scanf("%d",&a);
	if (a==1)
	{
		check(trhead,conhead,n);//按车次查找 
		menu(trhead,conhead,n);//回到菜单 
	} 
	else
	   if (a==2)
	   {
	   	   printf("购买车票");
	       buy(trhead,conhead);//购买车票 
	    } 
	   else 
	      if (a==3)
	      { 
	         printf("退订车票");
	         //returntr();//退订车票
	      }
		  else
		     if (a==4)
		     {
			     printf("改签车票");
		         //endorsetr();//改签车票
		     }
		     else
		        if (a==5)
		        {
		        	printf("谢谢使用！");
					exit (0);
				}
				
}

void tickets (pemp trhead,int n)//读数据函数 
{
	pemp p,q;
	FILE *fp;
	int i=0;
	q=trhead;
	
	fread(trhead,sizeof(node1)-8,1,fp);
	if (NULL==(fp=fopen("生成票量.txt","a+")))
	{
		printf("文件打开失败");
		exit(-1); 
	}
	p=(pemp)malloc(sizeof(node1));
	while (1==fread(p,sizeof(node1)-8,1,fp))
	{
		p->next=NULL;
		q->next=p;
		q=p;
		printf("车次号：%d",p->tnumber);
		p=(pemp)malloc(sizeof(node1));
	}
	/*
	FILE *fp;
	int i=0;
	
	if (NULL==(fp=fopen("生成票量.txt","rb")))
	{
		printf("can not open the file");
		exit (-1);
	}
	
	while (1==fread(&pointtr[i],sizeof(node1),1,fp))
	{
		i++;
	}
	if (!feof(fp))
	{
		printf("读取失败");
	}
	
	fclose(fp);
    */
}
/*
void check(pemp thread,consumer conhead,int n)//查询函数 
{
	int i,m=0,flag=0;
	pemp p,q;
	p=trhead;
	
	
	printf("请输入你要查找车辆的车次：");
	scanf("%d",&i);	
	while (i!=p->tnumber)
	{
		  q=p;
		  p=p->next;   
    } 
    if (p->tnumber=i)
    {
    	printf("硬座票有：%d\n硬卧票有：%d\n软卧票有：%d\n",p->Alnumber,p->Blnumber,p->Clnumber);
    	flag=1;
	}
	
	if (flag==0)
	{
	  printf("没有该车次,返回菜单。");
	  manu(trhead,conhead);
    }
	  
}

void buy(pemp trhead,consumer conhead)
{
	int i,a,b,c,tr;
	char name[10];
	char id[18];
	pemp p,q;
	p=trhead;
	FILE *fp;
	
	printf("请输入你的名字：");
	scanf("%s\n",name);
    printf("请输入你的身份证号：");
	scanf("%s\n",id);
	printf("请输入购票的车次；");
	scanf("%d\n",&tr);
	printf("请输入你要购买硬座,硬卧，软卧票的张数：(以a b c格式)：");
	scanf("%d%d%d",&a,&b,&c);
	fp=fopen("buyer.txt","a+");
	fscanf(fp,"%s%s%d%d%d",name,id,&a,&b,&c);
	
	while (i!=p->tnumber)
	{
		  q=p;
		  p=p->next;   
    } 
    if (p->tnumber=i)
    {
    	p->Alnumber=p->Alnumber-a;
    	p->Blnumber=p->Blnumber-b;
    	p->Clnumber=p->Clnumber-c;
	}
	else
	{
		printf("没有改车次，返回菜单。");]
		menu(trhead,conhead);
	}
	
	
}
*/
