#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> adjlist(n + 1);
    for (int i = 2; i <= n; i++) {
        int parent;
        cin >> parent;
        adjlist[parent].push_back(i);
    }

    int check;
    cin >> check;

    queue<pair<int, int>> q;
    q.push({1,0});
    while(!q.empty()){
        int curr = q.front().first;
        int d = q.front().second;
        q.pop();

        if(curr == check){
            cout<<d;
            return 0;
        }

        for(int adj: adjlist[curr]){
            q.push({adj, d+1});
        }
    }

    return 0;
}