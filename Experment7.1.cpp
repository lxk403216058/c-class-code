#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE -1
#define NULLKEY -1

typedef int Status;
typedef int KeyType;
typedef struct {
	KeyType key;
}ElemType;
typedef struct{
	ElemType *elem;
	int count;
	int sizeindex;
}HashTable;

void Init_HashTable(HashTable *);
int Hash(int ,HashTable *);
Status Search_Hash(HashTable ,KeyType ,int *,int *);
void collision(int *,int ,HashTable *);
void collision1(int *,int ,HashTable *);

int main(){
	
	return 0;
}



int Hash(int key,HashTable *H){
	return key%H->sizeindex;
}

Status Search_Hash(HashTable *H,KeyType K,int *p,int *c){
	
	(*p)=Hash(K,H);
	while (H->elem[*p].key != NULLKEY&&H->elem[*p].key != K)
	      collision(p,(*c)++);
	if (H->elem[*p].key = K)
	   return SUCCESS;
	else 
	   return UNSUCCESS;
}

void collision(int *p,int c,HashTable *H){
	p=(p+c)%H->sizeindex;
}
 
void collision1(int *p,int c,HashTable *){
	//p = 
}
 
