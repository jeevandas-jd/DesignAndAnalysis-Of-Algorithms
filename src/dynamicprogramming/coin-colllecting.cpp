#include <iostream>
#include <algorithm>
using namespace std;

int maxCoins(int** grid, int m, int n) {
    int dp[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = grid[i][j]; 
            } else if (i == 0) {
                dp[i][j] = grid[i][j] + dp[i][j - 1];
            } else if (j == 0) {
                dp[i][j] = grid[i][j] + dp[i - 1][j]; 
            } else {
                dp[i][j] = grid[i][j] + max(dp[i - 1][j], dp[i][j - 1]); 
            }
        }
    }

    return dp[m - 1][n - 1];  
}

int main() {
    int m = 3, n = 3;
    int gridValues[3][3] = {{1, 2, 3}, {0, 6, 1}, {4, 5, 9}};

    
    int* grid[m];
    for (int i = 0; i < m; i++) {
        grid[i] = gridValues[i];
    }

    cout << "Maximum coins collected: " << maxCoins(grid, m, n) << endl;

    return 0;
}
