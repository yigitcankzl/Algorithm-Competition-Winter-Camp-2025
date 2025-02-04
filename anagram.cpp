#include <bits/stdc++.h>

using namespace std;



bool checking(vector<int>& aBit, vector<int>& sBit) {
    return aBit == sBit;
}

int main() {
    string a, s;
    cin >> a >> s;
    
    vector<int> aBit(26,0);
    vector<int> sBit(26,0);


    int size_of_the_s = s.size();
    int size_of_the_a = a.size();


    if (size_of_the_s > size_of_the_a) {
        cout << 0;
        return 0;   
    }

    for (int i = 0; i < size_of_the_s; ++i) {
        sBit[s[i] - 'a']++;
    }
    for (int i = 0; i < size_of_the_s; ++i) {
        aBit[a[i] - 'a']++;
    }

    int count = 0;
    if (checking(aBit, sBit)) count++;

    for (int i = size_of_the_s; i < size_of_the_a; i++) {
        aBit[a[i] - 'a']++;     
        aBit[a[i - size_of_the_s] - 'a']--; 

        if (checking(aBit, sBit)) count++;
    }

    cout << count;
    return 0;
}
