#include <iostream>
#define MAX_TERMS 300
using namespace std;
typedef struct {
    int degree;
    int coef_int;//coef*10
    char positiveornegative;
}polynomial;
polynomial polynomial_all[MAX_TERMS];
void putinnumber(string);
int compare(int,int);
void printthesum();
void padd();
int k=0;//the item in the polynomial
int startA=0;
int finishA=0;
int startB=0;
int finishB=0;
int startC=0;
int finishC=0;
int main()
{
    for(int i=0;i<MAX_TERMS;i++)
    {
        polynomial_all[i].coef_int=0;
        polynomial_all[i].degree=0;
    }
    string polynomial_a="";
    cin >> polynomial_a;
    putinnumber(polynomial_a);
    startB=k;
    finishA=k-1;
    string polynomial_b="";
    cin >> polynomial_b;
    putinnumber(polynomial_b);
    startC=k;
    finishB=k-1;
    padd();
    finishC=k-1;
   // cout << "pn\tcoef\tdegree" << endl;

/*
    for(int i=startC;i<=finishC;i++)
    {
        cout << polynomial_all[i].positiveornegative <<"\t"<< polynomial_all[i].coef_int << "\t" <<polynomial_all[i].degree << endl;
    }
*/
    printthesum();
    return 0;
}
void putinnumber(string pol)
{
    int i=0;//the index of the polynomial_a_b(read it one by one)
    while(pol[i]!='\0')
    {
        if(pol[i]=='x')//the first is x
        {
            polynomial_all[k].positiveornegative='+';
            polynomial_all[k].coef_int=10;
        }else
        {
            if(pol[i]=='-'||pol[i]=='+')//determine positive or negative
                polynomial_all[k].positiveornegative=pol[i++];
            else
                polynomial_all[k].positiveornegative='+';

            if(pol[i]=='x')//coef 1 or not
                polynomial_all[k].coef_int=10;
            else
            {
                while( pol[i]>='0' && pol[i]<='9')//coef
                    polynomial_all[k].coef_int= (polynomial_all[k].coef_int)*10 + (pol[i++]-'0');
                if(pol[i]=='.')//coef whether have "."
                {
                    polynomial_all[k].coef_int=(polynomial_all[k].coef_int)*10 + (pol[++i]-'0');
                    i++;
                }
                else
                    polynomial_all[k].coef_int=(polynomial_all[k].coef_int)*10;
                if(pol[i]!='x')//if degree is 0
                {
                    // cout <<"i="<<i<<endl;
                     polynomial_all[k].degree=0;
                     k++;
                     break;
                }
            }
        }
        i+=2;
        while( pol[i]>='0' && pol[i]<='9')
        {
            //cout <<"i="<<i<<endl;
            polynomial_all[k].degree= (polynomial_all[k].degree)*10 + (pol[i++]-'0');
        }
        //cout <<"polynomial_all[0].degree="<<polynomial_all[0].degree<<endl;
        k++;
    }
}
void padd()
{
    while(startA<=finishA && startB<=finishB)
    {
        switch(compare(polynomial_all[startA].degree,polynomial_all[startB].degree))
        {
        case 1:
            polynomial_all[k++]=polynomial_all[startA++];
            break;
        case 0:
            polynomial_all[k].degree=polynomial_all[startA].degree;
            if(polynomial_all[startA].positiveornegative==polynomial_all[startB].positiveornegative)
            {
                polynomial_all[k].coef_int=polynomial_all[startA].coef_int + polynomial_all[startB].coef_int;
                polynomial_all[k].positiveornegative=polynomial_all[startB].positiveornegative;
            }else
            {
                 switch(compare(polynomial_all[startA].coef_int,polynomial_all[startB].coef_int))
                 {
                     case 1:
                        polynomial_all[k].coef_int=polynomial_all[startA].coef_int-polynomial_all[startB].coef_int;
                        polynomial_all[k].positiveornegative=polynomial_all[startA].positiveornegative;
                        break;
                     case 0:
                        polynomial_all[k].coef_int=0;
                        break;
                     case -1:
                        polynomial_all[k].coef_int=polynomial_all[startB].coef_int-polynomial_all[startA].coef_int;
                        polynomial_all[k].positiveornegative=polynomial_all[startB].positiveornegative;
                        break;
                 }
            }
            k++;
            startA++;
            startB++;
            break;
        case -1:
            polynomial_all[k++]=polynomial_all[startB++];
            break;
        }
    }
    while(startA<=finishA)
        polynomial_all[k++]=polynomial_all[startA++];
    while(startB<=finishB)
        polynomial_all[k++]=polynomial_all[startB++];
}
int compare(int a,int b)
{
    if( a > b )
        return 1;
    if( a == b )
        return 0;
    if( a < b )
        return -1;
}
void printthesum()
{
    bool beginornot = true;
    for(int i=startC;i<=finishC;i++)
    {
        if( polynomial_all[i].coef_int == 0)//is there anything?
            continue;
        if(!(beginornot && polynomial_all[i].positiveornegative=='+'))//out put + or -
            cout << polynomial_all[i].positiveornegative;
        if( polynomial_all[i].coef_int != 10 ||polynomial_all[i].degree==0)//out put coefficient
        {
            cout << polynomial_all[i].coef_int/10;
            if(polynomial_all[i].coef_int%10 != 0)
                cout << "." << polynomial_all[i].coef_int%10;//the number after point
        }
        if(polynomial_all[i].degree != 0 )
            cout << "x^" << polynomial_all[i].degree;
        beginornot = false;
    }
    if(beginornot == true)
         cout << "0" ;
}
