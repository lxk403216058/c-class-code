#include<stdio.h>
#include<stdlib.h>

struct STUDENT
{
	char name[20];
	int age;
	char sex;
	char num[20];
};

int main()
{
	int i;
	int cut;
	FILE *fp;
	struct STUDENT std[100];
	
	printf("�������뼸��ѧ������Ϣ��");
	scanf("%d",&cut);
	
	if (NULL==(fp=fopen("stu_list", "wb")))
	{
		printf("cant open the file");
		exit(-1);
	} 
	
	printf("��ֱ�����ѧ�������������䣬�Ա�ѧ�ţ�\n");

	for (i=0;i<cut;++i)
	{
		scanf("%s%d %c%s",std[i].name,&std[i].age,&std[i].sex,std[i].num);
		
		if (fwrite(&std[i],sizeof(struct STUDENT),1,fp)!=1)
		{
			printf("file write error\n");
		} 
	}
	
	fclose(fp);
	
	return 0;
 
 } 
