#include <iostream>
#define MAX_TERMS 100
typedef enum {Left,Right,Plus,Minus,Times,Divide,Mod,Eos,Operend}precedure;
typedef struct data
{
    int isp;
    int icp;
    char pre;
};
int isp[]={1,19,12,12,13,13,13,0};
int icp[]={20,19,12,12,13,13,13,0};
char infix[MAX_TERMS];
char postfix[MAX_TERMS]={};
int post = 0;
precedure getpre(char);
data Stack[MAX_TERMS];
void push(int,int,char);
void intopost();
char pop();
int top = -1;
using namespace std;
int main()
{
    cin >> infix;
    intopost();
    cout << postfix ;
    return 0;
}
void push(int isp_2,int icp_2,char pre_2)
{
    Stack[++top].icp=icp_2;
    Stack[top].isp=isp_2;
    Stack[top].pre = pre_2;
}
char pop()
{
    return Stack[top--].pre;
}
void intopost()
{
    precedure now;
    for(int i=0;i<MAX_TERMS;i++)
    {
        now=getpre(infix[i]);
        if(now==Eos)
        {
            while(top>=0)
                 postfix[post++]=pop();
            break;
        }
       if(now==Operend)
        {
             postfix[post++]=infix[i];
        }
        else if(now==Right)
        {
            while(Stack[top].isp != 1)
                postfix[post++]=pop();
            pop();
        }
        else
        {
            while(icp[now]<=Stack[top].isp&&top>=0)
                postfix[post++]=pop();
            push(isp[now],icp[now],infix[i]);
        }
    }

}
precedure getpre(char pre_2)
{
    switch(pre_2)
    {
        case '(': return Left;
        case ')': return Right;
        case '+': return Plus;
        case '-': return Minus;
        case '*': return Times;
        case '/': return Divide;
        case '%': return Mod;
        case '\0': return Eos;
        default :return Operend;
    }
}
