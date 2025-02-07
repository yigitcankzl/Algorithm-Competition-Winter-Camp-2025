#include <bits/stdc++.h>
using namespace std;

int checking(const multiset<int, greater<int>>& normal) {
    int bigone = 0;
    int count = 0;

    for (auto it = normal.begin(); it != normal.end(); ++it) {
        count++;
        if (*it >= count) {
            bigone = count;
        } else {
            break;
        }
    }
    return bigone;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   

    int m, n;
    cin >> m >> n;
    
    multiset<int, greater<int>> normal;
    int element;

    for (int i = 0; i < m; i++) {
        cin >> element;
        normal.insert(element);
    }

    int anw = checking(normal);  

    for (int j = 0; j < n; j++) {
        cin >> element;
        
        normal.insert(element);
        
        anw = checking(normal);
        cout << anw << "\n";
    }

    return 0;
}
