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
    for(int i=0;i<row_a*col_a;i++)
    {
        a[i].row=0;
        a[i].col=0;
        a[i].value=0;
    }
    for(int i=0;i<row_a;i++)
    {
        for(int j=0;j<col_a;j++)
        {
            cin >> val;
            if(val!=0)
            {
                a[k].row=i;
                a[k].col=j;
                a[k].value=val;
                k++;
            }
        }
    }
    //b
    cin >> row_b >> col_b;
    matrix b[row_b*col_b];
    matrix ob[row_b*col_b];
    for(int i=0;i<row_b*col_b;i++)
    {
        b[i].row=0;
        b[i].col=0;
        b[i].value=0;
        ob[i].row=0;
        ob[i].col=0;
        ob[i].value=0;
    }
    for(int i=0;i<row_b;i++)
    {
        for(int j=0;j<col_b;j++)
        {
            cin >> val;
            if(val!=0)
            {
                ob[l].row=i;
                ob[l].col=j;
                ob[l].value=val;
                l++;
            }
        }
    }

    int counting[col_b]={};
    int start[col_b]={};
    for(int i=0;i<l;i++)
        counting[ob[i].col]++;
    start[0]=0;
    for(int i=1;i<col_b;i++)
        start[i]=start[i-1]+counting[i-1];
    //cout << "start[0] " <<start[0]<< endl;
    for(int i=0;i<l;i++)
    {
        b[start[ob[i].col]].row=ob[i].row;
        b[start[ob[i].col]].col=ob[i].col;
        b[start[ob[i].col]].value=ob[i].value;
        start[ob[i].col]++;
    }
    for(int i=col_b-1;i>=1;i--)
        start[i]=start[i-1];
    start[0]=0;
    /*
    cout << "row \tcol \tvalue " << endl;
    for(int i =0;i<k;i++)
    {
        cout << a[i].row << "\t"<< a[i].col << "\t" << a[i].value << endl;
    }
    cout <<endl;
    for(int i =0;i<l;i++)
    {
        cout << b[i].row << "\t"<< b[i].col << "\t" << b[i].value << endl;
    }
    /*
     cout << "row \tcol \tvalue " << endl;
    for(int i =0;i<l;i++)
    {
        cout << ob[i].row << "\t"<< ob[i].col << "\t" << ob[i].value << endl;
    }

     cout << "row \tcol \tvalue " << endl;

    for(int i =0;i<l;i++)
    {
        cout << b[i].row << "\t"<< b[i].col << "\t" << b[i].value << endl;
    }
*/
    int startA=0;
    int startB=0;
    int p=0;
    matrix c[row_a*col_b];
    for(int i=0;i<row_a*col_b;i++)
    {
        c[i].row=0;
        c[i].col=0;
        c[i].value=0;
    }
    while( startA < k )//errow
    {
        int firstA = startA;
        for(int i =0;i<col_b;i++)
        {
            int val=0;
            for(int j=start[i]; j < (start[i]+counting[i]);j++)
            {
                if(a[startA].col == b[j].row)
                    val=val+a[startA].value*b[j].value;
                if(a[startA].col <= b[j].row)
                    startA++;
                if(a[startA].row>a[firstA].row)
                    break;
            }
            if(val!=0)
            {
                c[p].row=a[firstA].row;
                c[p].col=b[start[i]].col;
                c[p].value= val;
                p++;
            }
            startA = firstA;
        }
        while(a[startA].row==a[firstA].row)
            startA++;
    }
    /*
     cout << "row \tcol \tvalue " << endl;

    for(int i =0;i<p;i++)
    {
        cout << c[i].row << "\t"<< c[i].col << "\t" << c[i].value << endl;
    }
    */
    int m=0;
    for(int i=0;i<row_a;i++)
    {
        if(i!=0)
            cout << endl;
        for(int j=0;j<col_b;j++)
        {
            if(j!=0)
                cout << " ";
            if(c[m].row==i&&c[m].col==j)
            {
                cout << c[m].value;
                m++;
            }
            else
                cout << 0;
        }
    }
    /*
    int matrixc[row_a][col_b]={};
    for(int i=0;i<p;i++)
    {
        matrixc[c[i].row][c[i].col]=c[i].value;
    }
    for(int i=0;i<row_a;i++)
    {
        for(int j=0;j<col_b;j++)
        {
            cout << matrixc[i][j];
            if(j==(col_b-1))
            {
              if(i==(row_a-1))
                    break;
              cout << endl;
            }
            else
                cout << " ";
        }
    }
    /*
    cout << "i\trow \tcol \tvalue " << endl;
    for(int i = 0;i<row_a*col_b;i++)
    {
        cout << i << "\t"<< c[i].row << "\t"<< c[i].col << "\t" << c[i].value << endl;
    }
    */


    return 0;
}
