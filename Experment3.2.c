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
		DeQueue(&q,&qf); // ����qfΪ��ǰ��  
            for(i=0;i<8;i++) // �����������  
            {  
                qr.i=qf.i+direction[i][0]; // ��һ�������  
                qr.j=qf.j+direction[i][1];  
                if(maze[qr.i][qr.j] == 0 && mark[qr.i][qr.pre] == 0)  
                { // �˵���ͨ���Ҳ��������ʹ�  
                    mark[qr.i][qr.j]=-1; // ����ѷ��ʹ�  
                    qr.pre=q.rear-1-q.front; // qt��ǰһ�㴦�ڶ������ֶ�ͷ��1��λ��(ûɾ��)  
                    EnQueue(&q,qr); // ���qt  
                    if(qr.i== 10 &&qr.j==12) // �����յ�  
                    {  
                        flag=0;  
                        break;  
                    }  
                }  
            }  
	}
	if (flag == 1)
	   printf("û��·���ܵ����յ�");
	else{
	    InitStack(&s); // ��ʼ��sջ  
        i=q.rear-1-q.front; // iΪ����ջԪ���ڶ����е�λ��  
        while(i>=0) // û�����  
        {  
            Push(&s,*q.rear); // �������е�·����ջ(ջ��Ϊ���ڣ�ջ��Ϊ���)  
            i=q.rear -> pre; // iΪǰһԪ���ڶ����е�λ��  
        }  
        i=0; // iΪ�߳��Թ����㼣  
        while(!StackEmpty(s))  
        {  
            Pop(&s,q.front); // ��������ڵ����ڵ�˳�򵯳�·��  
            i++;  
            *maze[qf.i][qf.j]=i; // ���·��Ϊ�㼣(���ǰ��ֵΪ-1)  
        }  
        printf("�߳��Թ���һ��������\n");  
        }  

}

