#include <iostream>

#include <algorithm>

#include <vector>

#include <climits>

using namespace std;



int changemaking(int coins[],int num_coins,int ammount){

    int dp[ammount+1];

    for (int i=0;i<num_coins;i++){
        dp[i]=INT_MAX;
    }
    dp[0]=0;
    for(int i=0;i<ammount;i++){

        for(int j=0;j<num_coins;j++){

            if(coins[j]<=i && dp[i-coins[j]]!=INT_MAX){
                dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
        }
    }
    
    return dp[ammount];
}