#include <iostream>
#include <cmath>
using namespace std;


void MergeSort(int arr[],int len){
    if(len>1){
    int l=floor(len/2);
    int left[100];
    int right[100];
    for(int i=0;i<l;i++){
        left[i]=arr[i];
    }
    for(int j=0;j<len-l;j++){
        right[j]=arr[j+l];
    }
    MergeSort(left,l);
    MergeSort(right,len-l);


    int i,j,k;
    j=i=k=0;
    while(i<l && j<len-l){
        if(left[i]<right[j]){
            arr[k]=left[i];
            i=i+1;
        }
        else{
            arr[k]=right[j];
            j=j+1;
        }
    k=k+1;
    }
    while(i<l){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<l){
        arr[k]=right[j];
        j++;
        k++;
    }
    }
    

}
void print(int arr[],int len){
    cout<<"\n";
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }

}

int main(){

    int arr[10]={9,8,7,6,5,14,3,2,100};
    MergeSort(arr,9);
    print(arr,9);
}