#include<stdo.h>
#include<stdlib.h>

#define INFITY INT_MAX
#define MAX_VERTEX_NUM 20
typedef enum {
	DG,DN,AG,AN
} Graphkind;

typedef struct ArcCell{
	VRType adj;
	InfoType *info; 
} ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMtrix arcs;
	int vexnum,arcnum;
	GraphKind kind;
}MGraph;

int main(){
	
}
Status CreateUDG(MGraph &G){
	VertexType v1, v2;
	int w, i, j;
	printf("����������������G�Ķ��������������ö��Ÿ���\n");
    scanf("%d,%d", &G.vexnum, &G.arcnum);
    printf("����������������G�Ķ������ƣ��ÿո����\n");
    for (i=0;i<G.vexnum;i++)
	   scanf("%d", &G.vexs[i]);
	for (i=0;i<G.vexnum;i++)
	   for (j=0;j< )
}
