#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcs(const string& X, const string& Y) {
    int m = X.length(), n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // DP table

    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n]; // Return the length of the longest common subsequence
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    cout << "Length of the longest common subsequence: " << lcs(X, Y) << endl;
    return 0;
}