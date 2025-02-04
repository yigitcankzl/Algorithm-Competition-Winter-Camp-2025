#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define int long long

int32_t main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int &c : arr)
        cin >> c;


    vector<int> dp(k + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j <= k; j++) {
            dp[j] = max(dp[j], dp[j - arr[i]] + arr[i]);
        }
    }

    int ans = dp[k];
    
    cout << ans << "\n";
    
    return 0;
}