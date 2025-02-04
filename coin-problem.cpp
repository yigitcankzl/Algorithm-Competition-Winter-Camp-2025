#include <bits/stdc++.h>
#define ii pair<int,int>

using ll = long long;
using namespace std;
const int mod = 1e9 + 7;
const int INF = 1e9;

void solve() {
    int n, target; cin >> n >> target;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(target + 1, INF));

    for(int i = 0; i<= n; i++) 
        dp[i][0] = 0;
 

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= target; j++) {
            if (v[i] <= j) {
                dp[i][j] = min(dp[i-1][j], dp[i][j - v[i]] + 1);
            } else dp[i][j] = dp[i-1][j];
        }
    }

    cout << (dp[n][target] == INF ? -1 : dp[n][target]);


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while (t--) solve();
    
    return 0;
}