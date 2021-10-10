#include <iostream>
#define MAX_TERMS 100
typedef struct treenode* treepointer;
typedef struct treenode
{
    int data;
    treepointer leftchild;
    treepointer rightchild;

};
treepointer Stack[MAX_TERMS];
int top =-1;
void push(treepointer);
treepointer pop();
using namespace std;
treenode tree[MAX_TERMS];
int num;
bool first=true;
void gettree();
void postorder(treepointer);
int main()
{
    cin >>num;
    for(int i=0;i<num;i++)
    {
        cin >> tree[i].data;
        tree[i].leftchild =NULL;
        tree[i].rightchild =NULL;
    }
    treepointer root = &tree[0];
    if(tree[0].data==-1)
        cout <<"Empty tree!!";
    else
    {
        gettree();
        postorder(root);
    }
    return 0;
}
void gettree()
{
    for(int i=0;i<num;i++)
    {
        if(tree[i].data==-1)
            continue;
        if(i%2==1)
            tree[(i-1)/2].leftchild=&tree[i];
        else
            tree[(i-2)/2].rightchild=&tree[i];
    }
}
void postorder(treepointer ptr)
{
    while(1)
    {
        for(;ptr;ptr=ptr->leftchild)
        {
            if(first)
            {
                cout << ptr->data;
                first=false;
            }
            else
                cout <<" "<< ptr->data;
            push(ptr);
        }
        ptr=pop();
        if(!ptr)
            break;
        ptr=ptr->rightchild;
    }
}
void push(treepointer ptr)
{
    Stack[++top]=ptr;
}
treepointer pop()
{
    return Stack[top--];
}
