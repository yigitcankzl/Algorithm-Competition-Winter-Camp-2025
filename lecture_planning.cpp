#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;  

    vector<int> t(n), l(n);
    
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }

    sort(t.begin(), t.end());
    sort(l.begin(), l.end());

    int i = 0, j = 0, count = 0;


    while (i < n && j < n) {
        if (t[i] < l[j]) {  
            count++;  
            i++;  
            j++;  
        } else {
            j++; 
            if (j==n){
                j=0;
                i++;
            } 
        }
    }

    cout<<count;

    return 0;
}
