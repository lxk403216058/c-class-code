/* 
File: subject design
Description: ��ƱƱ�����ϵͳ
Programmer: Liang Xikuang
Date: 2018/03/06
*/ 

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct traininfor
{
	int tnumber;//���κ�
	int aprice;//Ӳ����Ʊ�۸�
	int bprice;//Ӳ�Գ�Ʊ�۸�
	int cprice; //���Գ�Ʊ�۸�
	int Alnumber;//����Ӳ��Ʊ��
	int Blnumber;//����Ӳ��Ʊ��
	int Clnumber;//��������Ʊ��
	struct traininfor *next;
};
typedef  struct traininfor node1,*pemp;

struct buyer
{
	char name[10];//��Ʊ������
	char id[18]; //��Ʊ�����֤�� 
	int Abnumber;//����Ӳ������ 
	int Bbnumber;//����Ӳ������
    int Cbnumber;//������������
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

void menu(pemp trhead,consumer conhead,int n)//�˵����� 
{
	int a;
	
	printf("\n\n\n\n\n                      ------------.o0Ŀ¼0o.------------\n");
	printf("                       1,��ѯ��Ʊ\n");
	printf("                       2,����Ʊ\n");
	printf("                       3,�˶���Ʊ\n");
	printf("                       4,��ǩ\n");
	printf("                       5,�˳�����\n");
	printf("                       ������ѡ����ţ�");
	scanf("%d",&a);
	if (a==1)
	{
		check(trhead,conhead,n);//�����β��� 
		menu(trhead,conhead,n);//�ص��˵� 
	} 
	else
	   if (a==2)
	   {
	   	   printf("����Ʊ");
	       buy(trhead,conhead);//����Ʊ 
	    } 
	   else 
	      if (a==3)
	      { 
	         printf("�˶���Ʊ");
	         //returntr();//�˶���Ʊ
	      }
		  else
		     if (a==4)
		     {
			     printf("��ǩ��Ʊ");
		         //endorsetr();//��ǩ��Ʊ
		     }
		     else
		        if (a==5)
		        {
		        	printf("ллʹ�ã�");
					exit (0);
				}
				
}

void tickets (pemp trhead,int n)//�����ݺ��� 
{
	pemp p,q;
	FILE *fp;
	int i=0;
	q=trhead;
	
	fread(trhead,sizeof(node1)-8,1,fp);
	if (NULL==(fp=fopen("����Ʊ��.txt","a+")))
	{
		printf("�ļ���ʧ��");
		exit(-1); 
	}
	p=(pemp)malloc(sizeof(node1));
	while (1==fread(p,sizeof(node1)-8,1,fp))
	{
		p->next=NULL;
		q->next=p;
		q=p;
		printf("���κţ�%d",p->tnumber);
		p=(pemp)malloc(sizeof(node1));
	}
	/*
	FILE *fp;
	int i=0;
	
	if (NULL==(fp=fopen("����Ʊ��.txt","rb")))
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
		printf("��ȡʧ��");
	}
	
	fclose(fp);
    */
}
/*
void check(pemp thread,consumer conhead,int n)//��ѯ���� 
{
	int i,m=0,flag=0;
	pemp p,q;
	p=trhead;
	
	
	printf("��������Ҫ���ҳ����ĳ��Σ�");
	scanf("%d",&i);	
	while (i!=p->tnumber)
	{
		  q=p;
		  p=p->next;   
    } 
    if (p->tnumber=i)
    {
    	printf("Ӳ��Ʊ�У�%d\nӲ��Ʊ�У�%d\n����Ʊ�У�%d\n",p->Alnumber,p->Blnumber,p->Clnumber);
    	flag=1;
	}
	
	if (flag==0)
	{
	  printf("û�иó���,���ز˵���");
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
	
	printf("������������֣�");
	scanf("%s\n",name);
    printf("������������֤�ţ�");
	scanf("%s\n",id);
	printf("�����빺Ʊ�ĳ��Σ�");
	scanf("%d\n",&tr);
	printf("��������Ҫ����Ӳ��,Ӳ�ԣ�����Ʊ��������(��a b c��ʽ)��");
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
		printf("û�иĳ��Σ����ز˵���");]
		menu(trhead,conhead);
	}
	
	
}
*/
