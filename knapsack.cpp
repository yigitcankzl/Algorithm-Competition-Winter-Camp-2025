#include <bits/stdc++.h>
#define ii pair<int, int>
 
using ll = long long;
using namespace std;
 
const int mod = 1e9 + 7;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, x;
    cin >> n >> x;
    vector<int> prices(n), pages(n);
    for (int &c : prices)
        cin >> c;
    for (int &c : pages)
        cin >> c;
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (prices[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            // 0-1 olduğu için üst satıra çıktık.
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - prices[i - 1]] + pages[i - 1]);
        }
    }
    cout << dp[n][x];
    return 0;
}