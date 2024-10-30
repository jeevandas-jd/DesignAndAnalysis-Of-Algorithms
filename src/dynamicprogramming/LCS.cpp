#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int LCS(const char* X, const char* Y, int m, int n) {
    int dp[m + 1][n + 1];

    // Initialize the dp array with 0
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    const char* X = "ABCBDAB";
    const char* Y = "BDCAB";
    int m = strlen(X);
    int n = strlen(Y);

    cout << "Length of LCS: " << LCS(X, Y, m, n) << endl;

    return 0;
}
