#include <bits/stdc++.h>
#define ii pair<int, int>

using ll = long long;
using namespace std;
const int mod = 1e9 + 7;

void solve() {
    int n, target;
    cin >> n >> target;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> dp(target + 1, 0);
    dp[0] = 1; 

    for (int j = 1; j <= target; j++) {
        for (int i = 0; i < n; i++) {
            if (j >= v[i]) {
                dp[j] = (dp[j] + dp[j - v[i]]) % mod;
            }
        }
    }

    cout << dp[target] << "\n";
}

int main() {

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}