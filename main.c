#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100

typedef struct {
    int degree;
    float coef;
}polynomial;

void padd(int,int,int,int);
int compare(int,int);
void attach(float,int,int);
void inputall(int);
polynomial term[MAX_TERMS];
char polynomials_a[MAX_TERMS];
char polynomials_b[MAX_TERMS];

int main()
{
    char co[MAX_TERMS]="";
    int i=0,avail=1,j=0,p=0;//i=the item in the string,j=the begin of coef,
    int startA=1;
    int startB=1;
    int finishA;
    int finishB;

    for( i=0;i<MAX_TERMS;i++)//initial
    {
        term[i].coef=0;
        term[i].degree=0;
    }
    scanf("%s%s",polynomials_a,polynomials_b);
    //printf("%s %s\n",polynomials_a,polynomials_b);
    //put polynomials_a into term
    for( i=0;i<MAX_TERMS;i++)
    {
        if(polynomials_a[i]== '\0')//if it is end
        {
             for(int p=0;p<MAX_TERMS;p++)
            {
                co[p]='\0';
                p++;
            }
            int m=0;
            for(j;j<i;j++)
            {
                co[m] = polynomials_a[j];
                m++;
            }
            term[avail].coef = atof (co);
            term[avail].degree = 0;
            p=0;
            avail++;
            break;
        }
        if(polynomials_a[i]=='x')
        {
            //put coef in the polynomail

            int m=0;
            p=0;
            for(int p=0;p<MAX_TERMS;p++)
            {
                co[p]='\0';
                p++;
            }
            if(polynomials_a[i-1]=='-')
                term[avail].coef = -1;
            else if(polynomials_a[i-1]=='+'||i==0)
                term[avail].coef = 1;
            else
            {
                 for(j;j<i;j++)
                {
                    co[m] = polynomials_a[j];
                    m++;
                }
                term[avail].coef = atof (co);
            }
            //find the degree
            i=i+2;//the number afer x^
            while(1)//find the degree(maybe >9)
            {
                term[avail].degree = term[avail].degree*10 + (polynomials_a[i]-'0');
                i++;
                if(polynomials_a[i]=='+'||polynomials_a[i]=='-'||polynomials_a[i]=='\0')
                    break;
            }
            j=i;
            avail++;
        }
        if(polynomials_a[i]== '\0')
            break;
    }
    i=0,j=0,startB=avail,finishA=avail-1;
    for(i=0;i<MAX_TERMS;i++)
    {
        if(polynomials_b[i]== '\0')//if it is end
        {
             for(int p=0;p<MAX_TERMS;p++)
            {
                co[p]='\0';
                p++;
            }
            int m=0;
            for(j;j<i;j++)
            {
                co[m] = polynomials_b[j];
                m++;
            }
            term[avail].coef = atof (co);
            term[avail].degree = 0;
            p=0;
            avail++;
            break;
        }
        if(polynomials_b[i]=='x')
        {
            //put coef in the polynomail

            int m=0;
            p=0;
           while(1)
            {
                co[p]='\0';
                p++;
                if(co[p]=='\0')
                    break;
            }
            if(polynomials_b[i-1]=='-')
                term[avail].coef = -1;
            else if(polynomials_b[i-1]=='+'||i==0)
                term[avail].coef = 1;
            else
            {
                 for(j;j<i;j++)
                {
                    co[m] = polynomials_b[j];
                    m++;
                }
                term[avail].coef = atof (co);
            }
            //find the degree
            i=i+2;//the number afer x^
            while(1)//find the degree(maybe >9)
            {
                term[avail].degree = term[avail].degree*10 + (polynomials_b[i]-'0');
                i++;
                if(polynomials_b[i]=='+'||polynomials_b[i]=='-'||polynomials_b[i]=='\0')
                    break;
            }
            j=i;
            avail++;
        }
        if(polynomials_b[i]== '\0')
            break;
    }
    finishB=avail-1;
    //now put all numbers in the struct start to add them together
    //for(i=1;i<MAX_TERMS;i++)
      //  printf("%5f%5d\n",term[i].coef,term[i].degree);
    padd(startA,startB,finishA,finishB);
   // printf("\n");
    //for(i=finishB+1;i<MAX_TERMS;i++)
      //  printf("%5f%5d\n",term[i].coef,term[i].degree);
    inputall(avail);
    return 0;
}

void padd(int startA,int startB,int finishA,int finishB)
{
    int k = finishB+1;
    float coefficient =0;
    while(startA <= finishA && startB <= finishB)
    {
        switch(compare(term[startA].degree,term[startB].degree))
        {
        case 1:
            attach(term[startA].coef,term[startA].degree,k);
            startA++;
            k++;
            break;
        case 0:
            coefficient = term[startA].coef + term[startB].coef;
            attach(coefficient,term[startA].degree,k);
            startA++;
            startB++;
            k++;
            break;
        case -1:
            attach(term[startB].coef,term[startB].degree,k);
            startB++;
            k++;
            break;
        }
    }
    while(startA <= finishA)
    {
        attach(term[startA].coef,term[startA].degree,k);
        startA++;
        k++;
    }
    while(startB <= finishB)
    {
        attach(term[startB].coef,term[startB].degree,k);
        startB++;
        k++;
    }
}
int compare(int expa,int expb)
{
    if(expa>expb)
        return 1;
    if(expa==expb)
        return 0;
    if(expa<expb)
        return -1;
}
void  attach(float coef,int exp,int k)
{
    if(k>=MAX_TERMS)
    {
        printf("Too many terms in the polynomial\n");
        exit(EXIT_FAILURE);
    }
    term[k].coef=coef;
    term[k].degree=exp;
}
void inputall(int k)
{
    int avail=k;
    int terms;
    for(k;k<MAX_TERMS;k++)
    {
        terms = term[k].coef*10;
        if(term[k].coef==0)
        {
            if(term[k].degree==0)
                break;
            continue;
        }
        if(term[k].coef>=0)
            if(avail!=k)
                printf("+");
        if((term[k].coef==-1||term[k].coef==1)&&term[k].degree!=0){
            if(term[k].coef==-1)
                printf("-");
        }
        else if (terms%10==0)
            printf("%1.0f",term[k].coef);
        else
            printf("%1.1f",term[k].coef);
        if(term[k].degree==0)
            break;
        else
            printf("x^%1d",term[k].degree);
    }
    // printf("\n");
}
