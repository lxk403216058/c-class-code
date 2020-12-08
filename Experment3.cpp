#include "StackHead.h"

Status Judge_Brackets(SqStack *,char *);

int main(){
	SqStack stack;
	int i;
	
	char str[10];
    printf("«Î ‰»Îƒ„“™ ‰»Îµƒ◊÷∑˚¥Æ£∫");
    scanf("%s",str);
    i=Judge_Brackets(&stack,str);
    if(i==FALSE)
        printf("¿®∫≈≤ª∆•≈‰");
    else
        printf("¿®∫≈∆•≈‰");

	return 1;
}

Status Judge_Brackets(SqStack *S,char *str){
	InitStack(S);
	int i = 0;
	SElemType ch;
	
	while(str[i]!='\0'){
		switch(str[i]){
			case '(':
				Push(S,'(');
				break;
			case '[':
				Push(S,'[');
				break;
			case '{':
				Push(S,'{');
				break;
			case ')':
				if (StackEmpty(*S))
				  return FALSE;
				else {
					Pop(S,&ch);
					if (ch != '(')
					   return FALSE;
				}
				break;
			case ']':
				if (StackEmpty(*S))
				  return FALSE;
				else {
					Pop(S,&ch);
					if (ch != '[')
					   return FALSE;
				}
				break;
			case '}':
				if (StackEmpty(*S))
				  return FALSE;
				else {
					Pop(S,&ch);
					if (ch != '{')
					   return FALSE;
				}
				break;
		}
		i ++;
	}
	if (!StackEmpty(*S))
	   return FALSE;
	
	return OK;
}
