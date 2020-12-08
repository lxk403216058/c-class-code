#include "Queue.h"
#include "StackHead.h"

Status MazePath(int ***); 

int main(){
	int maze[12][14] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1,
    1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1,
    1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1,
    1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1,
    1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1,
    1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1,
    1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1,
    1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

} 

Status MazePath(int ***maze){
	SqQueue q;
	SqStack s;
	QElemType qf,qr;
	int i=1,flag=1;
	qf.i = 1;
	qf.j = 1;
	qf.pre = -1;
	int direction[8][2] =  {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}}; 
	int mark[12][14] = {0};
	mark[qf.i][qf.j] = -1;
	InitQueue(&q);
	EnQueue(&q,qf);
	while (!QueueEmpty(q)&&flag){
		DeQueue(&q,&qf); // 出队qf为当前点  
            for(i=0;i<8;i++) // 向各个方向尝试  
            {  
                qr.i=qf.i+direction[i][0]; // 下一点的坐标  
                qr.j=qf.j+direction[i][1];  
                if(maze[qr.i][qr.j] == 0 && mark[qr.i][qr.pre] == 0)  
                { // 此点是通道且不曾被访问过  
                    mark[qr.i][qr.j]=-1; // 标记已访问过  
                    qr.pre=q.rear-1-q.front; // qt的前一点处于队列中现队头减1的位置(没删除)  
                    EnQueue(&q,qr); // 入队qt  
                    if(qr.i== 10 &&qr.j==12) // 到达终点  
                    {  
                        flag=0;  
                        break;  
                    }  
                }  
            }  
	}
	if (flag == 1)
	   printf("没有路径能到达终点");
	else{
	    InitStack(&s); // 初始化s栈  
        i=q.rear-1-q.front; // i为待入栈元素在队列中的位置  
        while(i>=0) // 没到入口  
        {  
            Push(&s,*q.rear); // 将队列中的路径入栈(栈底为出口，栈顶为入口)  
            i=q.rear -> pre; // i为前一元素在队列中的位置  
        }  
        i=0; // i为走出迷宫的足迹  
        while(!StackEmpty(s))  
        {  
            Pop(&s,q.front); // 依照由入口到出口的顺序弹出路径  
            i++;  
            *maze[qf.i][qf.j]=i; // 标记路径为足迹(标记前的值为-1)  
        }  
        printf("走出迷宫的一个方案：\n");  
        }  

}

