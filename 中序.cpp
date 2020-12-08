#include <stdio.h>
#include <stdlib.h>

typedef char TElemType;
typedef int Status;
#define TURE  1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define INFEASIBLE -2
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct {
	TElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

Status Create_BiTree(BiTree *);
Status Destory_BiTree(BiTree *);
void PreOrderTravel(BiTree);
void InOrderTraverse(BiTree);

int main() {
	BiTree BT;

	Create_BiTree(&BT);
	printf("\n���������");
	PreOrderTravel(BT);
	printf("\nZ���������");
	InOrderTraverse(BT);
	Destory_BiTree(&BT);
	system("pause");
}

Status Create_BiTree(BiTree *BT) {//�������д���������
	char ch;

	scanf("%c", &ch);
	if (ch == '#')
		BT = NULL;
	else {
		if (!(BT = (BiTree)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);
		Create_BiTree(&(*BT)->lchild);
		(*BT)->data = ch;
		Create_BiTree(&(*BT)->lchild);
	}


	return OK;
}

Status Destory_BiTree(BiTree *BT) {//���ٶ�����
	if (!*BT) {
		if ((*BT)->lchild)
			Destory_BiTree(&(*BT)->lchild);
		if ((*BT)->rchild)
			Destory_BiTree(&(*BT)->rchild);
		free(*BT);
		*BT = NULL;

	}

	return OK;
}

void PreOrderTravel(BiTree BT) {//�������������
	if (BT == NULL)
		return;
	printf("%c ", BT->data);
	PreOrderTravel(BT->lchild);
	PreOrderTravel(BT->rchild);
}

void InOrderTraverse(BiTree BT)//���������������
{
	if (BT == NULL)
		return 0;
	InOrderTraverse(BT->lchild);
	printf("%c ", BT->data);
	InOrderTraverse(BT->rchild);
}
