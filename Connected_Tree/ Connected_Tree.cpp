#include <iostream>
#define MAX_TERMS 100
#include <malloc.h>
using namespace std;
typedef struct node *nodepointer;
typedef struct node
{
    int data;
    nodepointer link;
};
nodepointer headnodes[MAX_TERMS];
int edges;
void DFS(int);
int vertices[MAX_TERMS];//no ->-1,find ->1,not find ->0
int main()
{
    cin >> edges;
    for(int i=0;i<MAX_TERMS;i++)
    {
        headnodes[i]=NULL;
        vertices[i]=-1;
    }

    int edge_1,edge_2;
    for(int i=0;i<edges;i++)
    {
        cin >> edge_1 >> edge_2;
        nodepointer ptr_1=headnodes[edge_1];
        if(!headnodes[edge_1])
        {
            headnodes[edge_1]=(nodepointer)malloc(sizeof(node));
            ptr_1=headnodes[edge_1];
        }else
        {
            while(ptr_1){
                //cout << "ptr_1:" <<ptr_1->data <<endl;
                if(!ptr_1->link)
                {
                    ptr_1->link=(nodepointer)malloc(sizeof(node));
                    ptr_1=ptr_1->link;
                    break;
                }
                ptr_1=ptr_1->link;
            }
        }
        ptr_1->data=edge_2;
        //cout << "headnodes[edge_1]:" <<ptr_1->data <<endl;
        ptr_1->link=NULL;

        nodepointer ptr_2=headnodes[edge_2];
        if(!headnodes[edge_2])
        {
            headnodes[edge_2]=(nodepointer)malloc(sizeof(node));
            ptr_2=headnodes[edge_2];
        }else
        {
            while(ptr_2){
                //cout << "ptr_2:" <<ptr_2->data <<endl;
                if(!ptr_2->link)
                {
                    ptr_2->link=(nodepointer)malloc(sizeof(node));
                    ptr_2=ptr_2->link;
                    break;
                }
                ptr_2=ptr_2->link;
            }
        }
        ptr_2->data=edge_1;
        ptr_2->link=NULL;
        //cout << "headnodes[edge_2]:" <<ptr_2->data <<endl;
        vertices[edge_1]=0;
        vertices[edge_2]=0;
    }
    bool Connected=true;
    DFS(edge_1);
    for(int i=0;i<MAX_TERMS;i++)
    {
        //cout << vertices[i]<<endl;
       if(vertices[i]==0)
       {
           Connected=false;
           //break;
       }
    }
    if(Connected)
        cout << "Connected!!" ;
    else
        cout <<"Not connected!!";

    return 0;
}
void DFS(int start)
{
    vertices[start]=1;
    nodepointer ptr;
    for(ptr=headnodes[start];ptr;ptr=ptr->link)
    {
        if(vertices[ptr->data]==0)
            DFS(ptr->data);
    }
}
