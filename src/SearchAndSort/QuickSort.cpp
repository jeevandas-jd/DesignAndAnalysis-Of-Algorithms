#include <iostream>
using namespace std;



int Partition(int low,int high,int Arr[]){
    int pivot=Arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if (Arr[j]<pivot){
            i++;
            int temp=Arr[i];
            Arr[i]=Arr[j];
            Arr[j]=temp;
            //swap(Arr[i],Arr[j]);    
        }
    }
    int t2=Arr[i+1];
    Arr[i+1]=Arr[high];
    Arr[high]=t2;
//swap(Arr[i+1],Arr[high]);

    return (i+1);
}

void QuickSort(int low,int high,int Arr[]){
    if(low<high){
        int flag=Partition(low,high,Arr);
        QuickSort(flag+1,high,Arr);
        QuickSort(low,flag-1,Arr);
    }


}

int main(){
    int arr[10];
    int el;
    for(int i=0;i<5;i++){
        cin>>arr[i];        
    }
    
    
    QuickSort(0,4,arr);
        for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}