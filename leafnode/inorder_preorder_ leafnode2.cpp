#include <iostream>
#include <malloc.h>
#define MAX_TERMS 100
using namespace std;
typedef struct treenode* treepointer;
typedef struct treenode
{
    int data;
    treepointer left;
    treepointer right;
};
int preorder[MAX_TERMS];
int inorder[MAX_TERMS];
int num;
void settree(treepointer,int,int,int,int);
int findinorder(int);
void leaf(treepointer);
int output[MAX_TERMS];
int top=-1;
void sortsort();
int main()
{
    cin >>num;

    for(int i=0;i<num;i++)
        cin >>preorder[i];
    for(int i=0;i<num;i++)
        cin >>inorder[i];
    treepointer root = (treepointer)malloc(sizeof(treenode));
    root->data=preorder[0];
    settree(root,0,findinorder(preorder[0]),num-1,0);
    leaf(root);
    sortsort();
    return 0;
}
int findinorder(int pre)
{
    for(int i=0;i<num;i++)
        if(inorder[i]==pre)
            return i;
}
void settree(treepointer ptr,int inLeft,int inNow,int inRight,int pre)
{
    if(inNow>inLeft)//has left children
    {
        ptr->left=(treepointer)malloc(sizeof(treenode));
        ptr->left->data=preorder[pre+1];
        settree(ptr->left,inLeft,findinorder(preorder[pre+1]),inNow-1,pre+1);
    }else
        ptr->left=NULL;


    if(inNow<inRight)
    {
        ptr->right=(treepointer)malloc(sizeof(treenode));
        ptr->right->data=preorder[pre+inNow-inLeft+1];
        settree(ptr->right,inNow+1,findinorder(preorder[pre+inNow-inLeft+1]),inRight,pre+inNow-inLeft+1);
    }else
        ptr->right=NULL;
}
void leaf(treepointer ptr)
{
    if(ptr->left)
        leaf(ptr->left);
    if(ptr->right)
        leaf(ptr->right);
    if(!ptr->right&&!ptr->left)
        output[++top]=ptr->data;
}
void sortsort()
{
    int Swap;
    for(int i =0;i<=top-1;i++)
    {
        for(int j=0;j<top-i;j++)
        {
            if(output[j]>output[j+1])
            {
                Swap=output[j+1];
                output[j+1]=output[j];
                output[j]=Swap;
            }
        }
    }
    for(int i =0;i<=top;i++)
    {
        if(i==0)
            cout << output[i];
        else
            cout << " " <<output[i];
    }
}
