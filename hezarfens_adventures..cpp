#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k, l;
    cin >> n >>k >>l;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }


    for(int i = 0; i < n-l; i++){
        int start = arr[i];
        int end = arr[i + l];
        bool fly = true;

        for (int j = i + 1; j <= i + l; j++) {
            if (arr[j] > start + k) {
                fly = false;
                break;
            }
        }

        if (fly) {
            for (int j = i + l - 1; j >= i; j--) {
                if (arr[j] > end + k) {
                    fly = false;
                    break;
                }
            }
        }
        if (fly) {
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }   
}