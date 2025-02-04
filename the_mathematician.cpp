//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> v(n);
    for (int i = 0; i< n; i++)
        cin >> v[i];
        
    int l = 0;
    int r = n - 1;
    int counter = 0;
    while (l < r)
    {
        float slope = (v[r] - v[l]) / (r - l);
        if (slope == m)
        {
            l++;
            r--;
            counter++;
        }
        else if (slope < m)
            l++;
        else
            r--;
    }
    cout << counter;
	return 0;
}