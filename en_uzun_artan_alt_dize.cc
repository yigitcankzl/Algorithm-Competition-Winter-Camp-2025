#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    vector<int> v = {5, 4, 3, 8, 7, 10, 6, 7, 8};
    vector<int> dp(v.size(), 1);
    for (int i = 0; i < v.size(); i++) {
        for(int j = 0; j < i; j ++) {
            if(v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < v.size(); i ++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";

}