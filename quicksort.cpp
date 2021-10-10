#include <iostream>
#define SWAP(a,b,t) ((t)=(a),(a)=(b),(b)=(t))
#define MAX 10
using namespace std;
int List[MAX];
void quicksort(int left,int right)
{
    int pivot,i,j,tmp=0;
    if(left<right)
    {
        i=left;
        j=right+1;
        pivot=List[left];
        do
        {
            do
                i++;
            while(List[i]<pivot);
            do
                j--;
            while(List[j]>pivot);
            if(i<j)
                SWAP(List[i],List[j],tmp);
        }while(i<j);
        SWAP(List[left],List[j],tmp);
        quicksort(left,j-1);
        quicksort(j+1,right);
    }
}
int main()
{
    int i=0;
    while(cin>>List[i])
        i++;
    quicksort(0,i-1);
    cout<<List[0];
    for(int j=1;j<i;j++)
        cout<<" "<<List[j];
    return 0;
}
