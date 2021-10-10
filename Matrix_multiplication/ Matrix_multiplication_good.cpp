#include <iostream>
using namespace std;
struct matrix{
    int row;
    int col;
    int value;
};
int main()
{
    int row_a,row_b,col_a,col_b,k=0,l=0;//k= a have value,l=b have value
    int val;
    //a
    cin >> row_a >> col_a;
    matrix a[row_a*col_a];
    for(int i=0;i<row_a;i++)
    {
        for(int j=0;j<col_a;j++)
        {
            cin >> val;
            if(val!=0)
            {
                a[k].row=i;
                a[k].col=j;
                a[k++].value=val;
            }
        }
    }
    //b
    cin >> row_b >> col_b;
    matrix b[row_b*col_b];
    for(int i=0;i<row_b;i++)
    {
        for(int j=0;j<col_b;j++)
        {
            cin >> val;
            if(val!=0)
            {
                b[l].row=i;
                b[l].col=j;
                b[l++].value=val;
            }
        }
    }
    int matrixc[row_a][col_b];
    for(int i=0;i<row_a;i++)
    {
        for(int j=0;j<col_b;j++)
        {
            matrixc[i][j]=0;
        }
    }
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<l;j++)
            if(a[i].col==b[j].row)
                 matrixc[a[i].row][b[j].col]=matrixc[a[i].row][b[j].col]+a[i].value*b[j].value;
    }
    for(int i=0;i<row_a;i++)
    {
        if(i!=0)
            cout << endl;
        for(int j=0;j<col_b;j++)
        {
            if(j!=0)
                cout << " ";
            cout << matrixc[i][j];
        }
    }
    return 0;
}
