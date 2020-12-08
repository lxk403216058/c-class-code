#include<stdio.h>
#include<stdlib.h>

struct STUDENT
{
	char name[20];
	int age;
	char sex;
	char num[20];
};

void read(struct STUDENT *);

int main()
{
	int i;
	struct STUDENT std[3];
	read(std);
	for (i=0;i<3;i++)
	{
		printf("姓名：%s,年龄：%d,性别：%c,学号：%s\n",std[i].name,std[i].age,std[i].sex,std[i].num);
	}
	
	return 0;
 } 
 
 void read(struct STUDENT std[])
 {
 	FILE *fp;
 	int i=0;
 	
 	if (NULL==(fp=fopen("stu_list","rb")))
 	{
 		printf("cant open the file");
 		exit (-1);
	 }
	 
	 while (1==fread(&std[i],sizeof(struct STUDENT),1,fp))
	 {
	 	++i;
	 }
	 if (!feof(fp))
	 {
	 	printf("read error");
	 }
	 
	 fclose(fp);
	 
 }
