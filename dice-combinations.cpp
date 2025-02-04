#include <bits/stdc++.h>
#define ii pair<int, int>

using ll = long long;
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
vector<int> dp(N, -1);

int f(int n) {
    if (dp[n] != -1)
        return dp[n];
    if (n == 0)
        return dp[0] = 1;
    int ans = 0;
    for (int i = 1; i <= 6; i++) {
        if (n >= i) {
            ans += f(n - i);
            ans %= mod;
        }
    }
    return dp[n] = ans;
}

void solve() {
    int n;
    cin >> n;
    cout << f(n) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}