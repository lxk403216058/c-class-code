#include "Queue.h"
#include "StackHead.h"

#define MAXSIZE 100

int main (){
	int **maze;
	
	
}
void menu(){
	int i;
	 
	printf("�˵���");
	printf("1.�Զ����Թ�");
	printf("2.��������Թ�");
	printf("3.�˳�");
	
	scanf("%d",&i);
	if (i == 1){
		
	}else if (i == 2){
		
	}else{
		system.exit(0);
	}
}

Status Artificial_Maze(int ***maze){
	int row,col;
	int start_x = 1,start_y = 1;
	int end_x = row,end_y = col;
	int i,j;
	
	printf("�������Թ���������")��
	scanf("%d",&row);
	printf("�������Թ���������");
	scanf("%d",&col);
	int end_x = row,end_y = col;
	*maze = (int**) malloc(sizeof(int*) * (row+2)) //[row+2][col+2];
	for(int i =0; i < row;i++)
	 (*maze)[i] = (int *)malloc(sizeof(int) * col)
	//int mark[row+2][col+2];
	
	for (i = 1;i < row;i ++){
		for (j = 1;j < col;j ++){
			int t;
			scanf("%d",&t);
			mark[row][col] = t;
		}
	}
	
	for (i = 0;i < row+2;i ++){
		for (j = 0;j < col+2;j ++){
			if (i=1&&j==1)
			   maze[i][j] = 0;
			else if (i==0||i=row+1||j==0||j=col+1)
			   maze[i][j]=1;
			else if (i==row||i=col)
			   maze[i][j]=0;
			else
			   maze[i][j]=mark[i][j];
		}
	}
	
	for (i=0;i<row+2;i++){
		for (j=0;j<col+2;j++){
			
		} 
	}
	
}
