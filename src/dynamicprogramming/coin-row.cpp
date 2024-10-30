#include <iostream>

#include <algorithm>


using namespace std;


int coinrow(int coin[],int n){

    if (n==0){
        return 0;
    }
    if (n==1){
        return coin[0];
    }

    int dp[n+1];

    dp[0]=0;
    dp[1]=coin[0];

    for(int i=2;i<=n;i++){

        dp[i]=max(dp[i-1],coin[i-1]+dp[i-2]);
    }

    return dp[n];
}


int main(){

    int coins[]={5,1,2,10,6};

    int res=coinrow(coins,5);

    cout<<"the maximim we can obtains equals to\t"<<res<<endl;


}


