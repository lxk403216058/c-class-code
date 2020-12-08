//maze_queue.cpp
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"queue.h"

#define MAX_ROW  12
#define MAX_COL  14

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

void print_line(void)
{    
    int i, j;
    system("cls");
    printf("�Թ����¡���������ǽ,���� ���ߡ����ʾ·��\n");
    for (i = 0; i < MAX_ROW; i++){
        for (j = 0; j < MAX_COL; j++)
            if (maze[i][j] == 1)       printf("��");
            else if (maze[i][j] >= 3){
                printf("%2d", maze[i][j] - 2);
            /*if (i == MAX_ROW-2 && j == MAX_COL-2)  printf("��");
            else                   printf("��");*/
            }
            else  printf("  ");
            printf("\n");
    }
printf("���ҵ���·...\n");
    printf("�ɼ����ö�������Թ����⣬�����ҳ�һ�����·��\n");
}

void visit(int row, int col,PSeqQueue S)
{
    struct point visit_point  = { row, col, S->front };
    maze[row][col] = 2;
    In_SeqQueue(S,visit_point);
}

int main()
{
    struct point p = { 1, 1, -1 };//��һ����ǰ����Ϊ-1���Ա�����ӡ�Թ�
    maze[p.row][p.col] = 2;//�������ĵ�����Ϊ2
    PSeqQueue S = Init_SeqQueue();
    In_SeqQueue(S,p);
    while (!Empty_SeqQueue(S)) 
    {
        Out_SeqQueue(S,&p);
        if (p.row == MAX_ROW - 2 && p.col == MAX_COL - 2)
            break;
        if (p.col + 1< MAX_COL-1 && maze[p.row][p.col + 1] == 0)
            visit(p.row, p.col + 1,S);
        if (p.row + 1< MAX_ROW-1 && maze[p.row + 1][p.col] == 0)
            visit(p.row + 1, p.col,S);
        if (p.col - 1 >= 1 && maze[p.row][p.col - 1] == 0)
            visit(p.row, p.col - 1,S);
        if (p.row - 1 >= 1 && maze[p.row - 1][p.col] == 0)
            visit(p.row - 1, p.col,S); //�����Ƕ��Թ����ĸ�������в���
    }
    if (p.row == MAX_ROW - 2 && p.col == MAX_COL - 2)//�Ƿ�Ϊ����
    {
        int count = 3;
        struct point q = { p.row, p.col, p.pre };
        while (q.pre != -1)//����ǰ�����в���
        {
            q = S->data[q.pre];
            count++;
        }
        printf("�ɹ��ҵ����·����·�����������\n");
        printf("(%d,%d)\n", p.row, p.col);
        maze[p.row][p.col] = count;
        while (p.pre!=-1)//����ǰ�����в���
        {
            count--;
            p = S->data[p.pre];
            maze[p.row][p.col] = count;
            printf("(%d,%d)\n", p.row, p.col);            
        }
        printf("������ӡ·��......\n");
        Sleep(3000);
        print_line();
    }

    else {
        printf("û�г�·\n");
    }
    
    system("pause");
    return 0;
}
//end maze_queue.cpp
