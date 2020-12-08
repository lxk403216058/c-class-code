#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
 
char LR0[50][50][100] = {{"S2"   ,"S3"   ,"null", "null" ,"null" ,"1"    ,"null" ,"null"},
                         {"null" ,"null" ,"null", "null" ,"acc " ,"null" ,"null" ,"null"},
                         {"null" ,"null" ,"S4"  , "S10"  ,"null" ,"null" ,"6"    ,"null"},
                         {"null" ,"null" ,"S5"  , "S11"  ,"null" ,"null" ,"null" ,"7"   },
                         {"null" ,"null" ,"S4"  , "S10"  ,"null" ,"null" ,"8"    ,"null"},
                         {"null" ,"null" ,"S5"  , "S11"  ,"null" ,"null" ,"null" ,"9"   },
                         {"r1"   ,"r1"   ,"r1"  , "r1"   ,"r1"   ,"null" ,"null" ,"null"},
                         {"r2"   ,"r2"   ,"r2"  , "r2"   ,"r2"   ,"null" ,"null" ,"null"},
                         {"r3"   ,"r3"   ,"r3"  , "r3"   ,"r3"   ,"null" ,"null" ,"null"},
                         {"r5"   ,"r5"   ,"r5"  , "r5"   ,"r5"   ,"null" ,"null" ,"null"},
                         {"r4"   ,"r4"   ,"r4"  , "r4"   ,"r4"   ,"null" ,"null" ,"null"},
                         {"r6"   ,"r6"   ,"r6"  , "r6"   ,"r6"   ,"null" ,"null" ,"null"},
                          };
char L[200]="abcd#EAB";   
int  del[10]={0,2,2,2,1,2,1};
char head[20]={'S','E','E','A','A','B','B'};
stack<int>con;   
stack<char>cmp;  
char cod[300]="0";
int cindex = 0;
char sti[300]="#";
int sindex = 0;
int findL(char b)
{
    for(int i = 0; i <= 7; i++)
    {
        if(b==L[i])
        {
            return i;
        }
    }
    return -1;
}
void error(int x, int y)       
{
    printf("µÚ%dÐÐ%cÁÐÎª¿Õ!",x,L[y]);
}
 
int calculate(int l, char s[])
{
    int num = 0;
    for(int i = 1; i < l; i ++)
    {
        num =  num*10+(s[i]-'0');
    }
    return num;
}
void analyze(char str[],int len)
{
    int cnt = 1;
    printf("²½Öè      ×´Ì¬Õ»    ·ûºÅÕ»    ÊäÈë´®    ACTION    GOTO\n");
    int LR = 0;
    while(LR<=len)
    {
        printf("(%d)       %-10s%-10s",cnt,cod,sti);
        cnt++;
        for(int i = LR; i < len; i++)
        {
            printf("%c",str[i]);
        }
        for(int i = len-LR; i<10;i++)printf(" ");
 
        int x = con.top();
        int y = findL(str[LR]);
 
        if(strcmp(LR0[x][y],"null")!=0)
        {
            int l = strlen(LR0[x][y]);
 
            if(LR0[x][y][0]=='a')///acc
            {
                printf("acc        \n");
                return ;
            }
            else if(LR0[x][y][0]=='S')
            {
                printf("%-10s \n",LR0[x][y]);
                int t = calculate(l,LR0[x][y]);
                con.push(t);
                sindex++;
                sti[sindex] = str[LR];
                cmp.push(str[LR]);
                if(t<10)
                {
                    cindex++;
                    cod[cindex] = LR0[x][y][1];
                }
                else
                {
                    int k = 1;
                    cindex++;
                    cod[cindex] = '(';
                    while(k<l)
                    {
                        cindex++;
                        cod[cindex] = LR0[x][y][k];
                        k++;
                    }
                    cindex++;
                    cod[cindex] = ')';
                }
                LR++;
            }
            else if(LR0[x][y][0]=='r')
            {
                printf("%-10s",LR0[x][y]);
                int t = calculate(l,LR0[x][y]);
                int g = del[t];
                while(g--)
                {
                    con.pop();
                    cmp.pop();
                    sti[sindex] = '\0';
                    sindex--;
                }
                g = del[t];
                while(g>0)
                {
                    if(cod[cindex]==')')
                    {
                        cod[cindex]='\0';
                        cindex--;
                        for(;;)
                        {
                            if(cod[cindex]=='(')
                            {
                                cod[cindex]='\0';
                                cindex--;
                                break;
                            }else
                            {
                                cod[cindex]='\0';
                                cindex--;
                            }
                        }
                        g--;
                    }else
                    {
                        cod[cindex] = '\0';
                        cindex--;
                        g--;
                    }
                }
                cmp.push(head[t]);
                sindex++;
                sti[sindex] = head[t];
                x = con.top();
                y = findL(cmp.top());
                t = LR0[x][y][0]-'0';
                con.push(t);
                cindex++;
                cod[cindex] = LR0[x][y][0];
                printf("%-10d\n",t);
            }else
            {
                int t = LR0[x][y][0]-'0';
                char ch = ' ';
                printf("%-10c%-10d\n",ch,t);
                con.push(t);
                cindex++;
                cod[cindex] = LR0[x][y][0];
                sindex++;
                sti[sindex] = 'E';
                LR++;
            }
        }else
        {
            error(x,y);
            return ;
        }
    }
 
}
int main()
{
    con.push(0);
    cmp.push('#');
    char str[200];
    cout<<"ÇëÊäÈë×Ö·û´®£¨´ø#£©£º"<<endl;
    cin>>str;
    int len = strlen(str);
    analyze(str,len);
    return 0;
}

