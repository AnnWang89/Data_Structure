/*****
HW5
*****/
#include <iostream>
#include<malloc.h>
#define MAX_STACK_SIZE 100
using namespace std;
typedef struct listNode *treepointer;
typedef struct listNode{
    int data;
    treepointer left_child;
    treepointer right_child;
};

void postorder(treepointer);
bool first=true;
int main()
{
    int number;
    cin >> number ;
    listNode tree[number];
    for( int i=0; i<number ;i++)
    {
        cin >> tree[i].data;
        tree[i].left_child=NULL;
        tree[i].right_child=NULL;
    }
    treepointer root;
    root = &tree[0];
    for(int i=1;i<number ;i++)
    {
        if(tree[i].data==-1)
            continue;
        if(i%2==0)
            tree[(i-2)/2].right_child = &tree[i];
        else
            tree[(i-1)/2].left_child = &tree[i];
    }
    if(root->data==-1)
        cout << "Empty tree!!";
    else
        postorder(root);
    return 0;
}
void postorder(treepointer ptr){

    if(ptr)
    {
        postorder(ptr->left_child);
        postorder(ptr->right_child);
        if(first)
        {
            cout << ptr->data ;
            first=false;
        }else
            cout << " " << ptr->data ;
    }
}
