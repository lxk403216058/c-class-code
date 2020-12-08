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
	
	printf("您想输入几个学生的信息：");
	scanf("%d",&cut);
	
	if (NULL==(fp=fopen("stu_list", "wb")))
	{
		printf("cant open the file");
		exit(-1);
	} 
	
	printf("请分别输入学生的姓名，年龄，性别，学号：\n");

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
