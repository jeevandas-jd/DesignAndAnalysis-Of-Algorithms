#include <iostream>
using namespace std;
int partition(int A[],int n,int low)
{
    int pivot=A[n];
    int i=low-1;
    for(int j=low;j<n;j++)
    {
        if(A[j]<=pivot)
        {
            i++;
            int temp=A[j];
            A[j]=A[i];
            A[i]=temp;
        }
    }
    int temp1=A[n];
    A[n]=A[i+1];
    A[i+1]=temp1;
    return i+1;
}
void QuickSort(int A[],int LB,int UB)
{
    if(LB<UB)
    {
        int pos1=partition(A,UB,LB);
        QuickSort(A,LB,pos1-1);
        QuickSort(A,pos1+1,UB);
    }
}
void Display(int A[],int n)
{
    for(int k=0;k<n;k++)
    {
        cout<<A[k]<<" ";
    }
}
int main()
{
    int n;
    int i=0;
    cout<<"Enter the number of elements : "<<endl;
    cin>>n;
    int A[n];
    while(i<n)
    {
        cout<<"Enter the elements : "<<endl;
        cin>>A[i];
        i++;
    }
    QuickSort(A,0,n);
    Display(A,n);  
}