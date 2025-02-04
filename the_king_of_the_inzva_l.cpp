#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    cin >> n;  
    cin >> m;  


    vector<int> g(n);
    
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    sort(g.begin(), g.end());

    for (int j= 0; j< m; j++) {
        int deger;
        cin >>deger;

        auto index = upper_bound(g.begin(), g.end(),deger);
        
        if (index != g.end()) {
            cout << *index <<endl;
        } else {
            cout << "-1"<<endl;
        }
    }

    return 0;
}
