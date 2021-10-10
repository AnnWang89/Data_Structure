#include <iostream>
#define MAX_TERMS 100
using namespace std;
int edgesweight[MAX_TERMS][MAX_TERMS];
int edge,cost=0;
int graph[MAX_TERMS];
int top=0;
int Prim(int);
int vertex[MAX_TERMS];
int main()
{
    cin >>edge;
    for(int i=0;i<MAX_TERMS;i++)
    {
        vertex[i]=-1;
        for(int j=0;j<MAX_TERMS;j++)
            edgesweight[i][j]=1000;
    }
    int edge_1,edge_2,weight;
    for(int i=0;i<edge ;i++)
    {
        cin >> edge_1 >> edge_2 >> weight;
        edgesweight[edge_1][edge_2]=weight;
        edgesweight[edge_2][edge_1]=weight;
        vertex[edge_1]=0;
        vertex[edge_2]=0;
    }
/*
    for(int i=0;i<MAX_TERMS;i++)
    {
        for(int j=0;j<MAX_TERMS;j++)
           cout << edgesweight[i][j]<<" ";
           cout <<endl;
    }
*/
    cout << Prim(edge_1) ;
    return 0;
}
int Prim(int start)
{
    vertex[start]=1;
    graph[top++]=start;
    while(1)
    {
        int mincost=1000;
        int min_j;
        for(int i=0;i<top;i++)
        {
            for(int j=0;j<MAX_TERMS;j++)
                if(mincost>edgesweight[graph[i]][j]&&vertex[j]==0)
                {
                    mincost=edgesweight[graph[i]][j];
                    min_j=j;
                }

        }
        graph[top++]=min_j;
        vertex[min_j]=1;
        //cout <<"cost: "<<cost<<endl;
        cost =cost + mincost;
        bool findall=true;
        for(int i=0;i<MAX_TERMS;i++)
            if(vertex[i]==0)
            {
                findall=false;
                break;
            }
        if(findall)
            return cost;
    }
}
