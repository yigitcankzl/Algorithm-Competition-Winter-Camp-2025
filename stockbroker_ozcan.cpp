#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;  
  
    unordered_set<int> set;
    int count=0;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;  
        if (set.find(value) == set.end()) {
            set.insert(value);
            
        }else{
            count++;
        }
    }
    
    cout<<count;
    return 0;
}
