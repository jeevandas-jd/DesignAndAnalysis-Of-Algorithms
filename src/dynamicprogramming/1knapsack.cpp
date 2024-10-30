#include <iostream>

#include <algorithm>

using namespace std;

int max(int a,int b){
    if(a<b){
        return b;
    }
    else{
        return a;
    }
}
int Knapsack(int weights[],int values[],int n,int capacity){

    int dp[n+1][capacity+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=capacity;j++){

            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if (weights[i-1]<=j)
            {
                dp[i][j]=max(dp[i-1][j],values[i-1]+dp[i-1][j-weights[i-1]]);
            }

            else{
                dp[i][j]=dp[i-1][j];
            }
            
        }

    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=capacity;j++){
            cout<<dp[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return dp[n][capacity];
}

int main(){
    int weights[]={1,3,4,5};
    int values[]={1,4,5,7};
    int res=Knapsack(weights,values,4,7);

    cout<<"the maximum value gained is equals to\t"<<res<<endl;

}