#include "bits/stdc++.h"
using namespace std;

#define int long long

int32_t main() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> prefix(n + 1, 0);
    for(int i = 0; i < n; i ++) {
        cin >> v[i];
        prefix[i + 1] = prefix[i] + v[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, LLONG_MAX));
    for(int i = 0; i <= n; i ++) {
        dp[i][i] = 0;
    }
    for(int len = 2; len <= n; len ++) {
        for (int i = 0; i + len - 1 < n; i ++) {
            int j = i + len - 1;
            for(int k = i; k < j; k++){
                int cost = dp[i][k] + dp[k + 1][j] + prefix[j + 1] - prefix[i];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    cout << dp[0][n - 1] << "\n";
    return 0;
}