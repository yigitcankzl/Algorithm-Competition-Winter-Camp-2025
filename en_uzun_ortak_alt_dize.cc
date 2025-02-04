#include "bits/stdc++.h"
using namespace std;

int main() {
    string s1, s2;
    s1 = "AGGTAB";
    s2 = "GXTXAYB";
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int en_buyuk = 0;
    for(int i = 0; i <= n; i ++) {
        for(int j = 0; j <= m; j ++) {
            
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                en_buyuk = max(en_buyuk, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    cout << en_buyuk << "\n";
}
