#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxCoins(const vector<int>& coins) {
    int n = coins.size();
    if (n == 0) return 0;      // No coins
    if (n == 1) return coins[0]; // Only one coin
    
    vector<int> dp(n);
    dp[0] = coins[0];           // Base case: take the first coin
    dp[1] = max(coins[0], coins[1]); // Base case: max of first two coins
    
    for (int i = 2; i < n; i++) {
        // Choose the max between taking the current coin and not taking it
        dp[i] = max(coins[i] + dp[i - 2], dp[i - 1]);
    }
    
    return dp[n - 1]; // Maximum value collected
}

int main() {
    vector<int> coins = {5, 1, 2, 10, 6}; // Example coin values
    int result = maxCoins(coins);
    cout << "Maximum coins that can be collected: " << result << endl;
    return 0;
}
