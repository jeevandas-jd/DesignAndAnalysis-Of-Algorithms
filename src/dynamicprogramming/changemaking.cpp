#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int changemaking(int coins[], int num_coins, int amount) {
    int dp[amount + 1];

  
    for (int i = 0; i <= amount; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;

    
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < num_coins; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }
    
   
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    int coins[] = {1, 3, 4};
    int num_coins = sizeof(coins) / sizeof(coins[0]);
    int amount = 6;

    int result = changemaking(coins, num_coins, amount);
    if (result != -1) {
        cout << "Minimum coins required: " << result << endl;
    } else {
        cout << "Not possible to make the amount with given coins" << endl;
    }

    return 0;
}
