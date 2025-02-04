#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    int n,m;
    cin >> n;  
    cin >> m;  


    vector<int> a(n);
    vector<int> b(m);

    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int j= 0; j< m; j++) {
        cin >> b[j];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());


    int count=0;
    int index=0;

    for (int k = 0; k < n; k++) {
        while (index < m && b[index] < a[k]) {
            index++;
        }
        count +=(m -index);
        
    }
    cout<< count<<endl;

    return 0;
}
