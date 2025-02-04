#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> dp(1000, vector<int>(1000, -1));

int editDist(string s1, string s2, int s1_size, int s2_size) {
    if (s1_size == 0) return s2_size;
    if (s2_size == 0) return s1_size;

    if (dp[s1_size][s2_size] != -1) return dp[s1_size][s2_size];

    if (s1[s1_size - 1] == s2[s2_size - 1]) {
        dp[s1_size][s2_size] = editDist(s1, s2, s1_size - 1, s2_size - 1);
    } 
    else {
        dp[s1_size][s2_size] = 1 + min({
            editDist(s1, s2, s1_size, s2_size - 1),    // Insert
            editDist(s1, s2, s1_size - 1, s2_size),    // Remove
            editDist(s1, s2, s1_size - 1, s2_size - 1) // Replace
        });
    }
    return dp[s1_size][s2_size];

}

int32_t main() {
    string s1 = "inzva";
    string s2 = "inzvac";
    string s1, s2;
    int length1,length2,k;
    cin >>length1>>length2>>k;

    cin>>s1>>s2;

    cout << editDist(s1, s2, s1.size(), s2.size());
    return 0;
}
