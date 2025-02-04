//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    
    int l = 0;
    int r = s.size() - 1;
    
    while (l <= r)
    {
        if (s[l] == '#' and s[r] == '#')
        {
            cout << -1 << endl;
            return 0;
        }
        
        else if (s[l] == '#')
            s[l] = s[r];
            
        else if (s[r] == '#')
            s[r] = s[l];
        
        else if (s[r] != s[l]) {
            cout << -1 << endl;
            return 0;
        }
        
        l++;
        r--;
    }
    
    cout << s << endl;

	return 0;
}