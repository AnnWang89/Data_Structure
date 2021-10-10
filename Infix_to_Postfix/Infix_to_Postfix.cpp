#include <iostream>
#define MAX_TERM 500
typedef enum {Lparen,Rparen,Plus,Minus,Times,Divide,Mod,Eos,Operand} precedence;
using namespace std;
/****************
HW4
****************/
typedef struct{//the road it walk
    int isp;
    int icp;
    char pre;
}Stack;
Stack Stack_token[MAX_TERM];
void postfix();
precedence gettoken(char);
void push(int,int,char);
Stack pop();
int top = -1;
char infix[MAX_TERM];
int isp[] = {1,19,12,12,13,13,13,0};
int icp[] = {20,19,12,12,13,13,13,0};
int main()
{
    cin >> infix;
    //Stack_token[top].icp =0;
    //Stack_token[top].isp =0;
    postfix();
    return 0;
}
void postfix(){
    precedence token;
    char post[MAX_TERM]={};
    Stack stackpost;
    int n=-1;
    for(int i=0;i<MAX_TERM;i++)
    {
        token = gettoken(infix[i]);
        //cout << "token " << token << endl;
        if(token == Eos)
        {
            while(top >= 0)
            {
                stackpost = pop();
                post[++n] = stackpost.pre;
            }
            break;
        }
        if(token == Operand)
        {
            post[++n]=infix[i];
            //cout << post << endl;
        }
        else
        {
            if(token == Rparen)
            {
                 while(Stack_token[top].isp != 1)
                 {
                    stackpost = pop();
                    post[++n] = stackpost.pre;
                    //cout << post << endl;
                 }
                 pop();
            }
            else
            {
                //cout << "stack " << Stack_token[top].pre << endl;
                while(Stack_token[top].isp >= icp[token]&& top>=0)
                {
                    stackpost = pop();
                    post[++n] = stackpost.pre;
                    //cout << post << endl;
                }
                push(isp[token],icp[token],infix[i]);
            }
        }
    }
    cout << post ;
    //cout << "<<" ;
}
precedence gettoken(char token){
    switch(token)
    {
        case '(' : return Lparen;
        case ')' : return Rparen;
        case '+' : return Plus;
        case '-' : return Minus;
        case '/' : return Divide;
        case '*' : return Times;
        case '%' : return Mod;
        case '\0' : return Eos;
        default  : return Operand;
    }
}
void push(int isp_2,int icp_2,char pre_2)
{
   Stack_token[++top].isp= isp_2;
   Stack_token[top].icp= icp_2;
   Stack_token[top].pre= pre_2;
}
Stack pop()
{
    return Stack_token[top--];
}
