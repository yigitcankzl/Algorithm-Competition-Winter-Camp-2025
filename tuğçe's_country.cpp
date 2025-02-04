#include <bits/stdc++.h>
using namespace std;

#define int long long
void iterativeDFS(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> adj(n + 1);  
    
    vector<bool> visited(n + 1, false); 
    int count=0;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            count++;
            iterativeDFS(i, adj, visited);
        }
    }
    cout << count << "\n";
    return 0;
}
