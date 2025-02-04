//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        
        vector<float> v(n);
        for (int i = 0; i < n; i++)
        {
            float x, y; cin >> x >> y;
            if (x == 0)
                v[i] = 90;
            else
                v[i] = atan(y / x) * 180 / M_PI;
        }
        
        sort(v.begin(), v.end());
        float minimum = 90.0;
        int l = 0;
        int r = k - 1;
        for (int i = 0; i < n - k + 1; i++)
            minimum = min(minimum, v[r + i] - v[l + i]);
        
        cout << fixed << setprecision(2) << minimum << endl;
    }
	return 0;
}