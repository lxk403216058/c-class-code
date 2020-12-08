#include<stdio.h>

int main()
{
	FILE *fp=fopen("text.txt","r");
	
	if (NULL==fp)
	{
		printf("can not open the file!\n");
	}
	else
	  printf("open  success!\n");
	  
	return 0;
 } 
