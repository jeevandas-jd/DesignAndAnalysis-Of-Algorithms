#include <iostream>
using namespace std;
void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}
int partition(int arr[],int h,int l){
    int pivot=arr[h-1];
    int flag=l-1;
    for(int i=l;i<h;i++){
        if(arr[i]<pivot){
            flag++;
            swap(arr[flag], arr[i]);


        }

    }
     swap(arr[flag + 1], arr[h]);
    return (flag+1);
}

void quickSort(int arr[],int h,int l){
    if(l<h){
    int p=partition(arr,h,l);
    quickSort(arr,p-1,l);
    quickSort(arr,h,p+1);
    }


}
void print(int arr[],int len){
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int arr[10]={9,8,7,6,5,4,3,2,1};
    quickSort(arr,9,0);
    print(arr,9);
}