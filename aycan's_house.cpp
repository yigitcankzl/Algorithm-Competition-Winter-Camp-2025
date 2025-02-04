#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;  

    vector<int> array(n);
    vector<int> prefixSum(n);

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    map<int,int> map;

    prefixSum[0]=array[0];
    map[prefixSum[0]] = 0;
    
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] +array[i];
        map.insert({prefixSum[i], 0});
    }

    int count=0;

    for (int i = 0; i < n; i++) {
        int val=map[prefixSum[i]];
        count +=val;
        map[prefixSum[i]]++;
    }

    int zeros =map[0];
    count +=zeros;

    cout<< count;
    return 0;
}

