#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define int long long

int32_t main(){
    int N, W;
    cin >> N >> W;
    
    vector<int> weight(N), value(N);
    int sumValues = 0;
    for (int i = 0; i < N; i++){
        cin >> weight[i] >> value[i];
        sumValues += value[i];
    }
    vector<int> dp(sumValues + 1, LLONG_MAX);
    dp[0] = 0;
    
    for (int i = 0; i < N; i++){
        for (int v = sumValues; v >= value[i]; v--){
            dp[v] = min(dp[v], dp[v - value[i]] + weight[i]);
        }
    }

    int ans = 0;
    for (int v = sumValues; v >= 0; v--){
        if (dp[v] <= W) {
            ans = v;
            break;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}