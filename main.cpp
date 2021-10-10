#include <iostream>
#define MAX_TERMS 100
using namespace std;
typedef struct node
{
    int data;
    bool Find;
};
int main()
{
    int number;
    int inorder[MAX_TERMS];
    int output[MAX_TERMS];
    int top =-1;
    node preorder[MAX_TERMS];
    cin >> number;
    for(int i=1;i<=number;i++)
        cin >> inorder[i] ;
    for(int i=1;i<=number;i++)
    {
        cin >> preorder[i].data ;
        preorder[i].Find = false;
    }
    preorder[0].Find = true;
    preorder[number+1].Find = true;
    for(int i=1 ; i<=number ;i++)
    {
        int indexpre=0;
        for(int j=1 ; j<=number ;j++)
        {
            if(inorder[i]==preorder[j].data)
                indexpre=j;
        }
        if(preorder[indexpre-1].Find&&preorder[indexpre+1].Find)
            output[++top]=preorder[indexpre].data;
        preorder[indexpre].Find = true;
    }
    int Swap;
    for(int i = 0;i<top;i++)
    {
        for(int j=0;j<top-i;j++ )
        {
            if(output[j]>output[j+1])
            {
                Swap=output[j+1];
                output[j+1]=output[j];
                output[j]=Swap;
            }
        }
    }
    cout << output[0]  ;
    for(int i = 1;i<=top;i++)
        cout << " " << output[i]  ;
    return 0;
}
