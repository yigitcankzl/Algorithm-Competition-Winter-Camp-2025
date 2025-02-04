#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    // vector<vector<pair<int, int>>> adj(n+1); // uncomment if weighted graph
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // int weight; // uncomment if weighted graph
        // cin >> weight; // uncomment if weighted graph
        adj[u].push_back(v);
        adj[v].push_back(u); // comment if directed
        // adj[u].push_back({v, weight}); // uncomment if weighted graph
        // adj[v].push_back({u, weight}); // uncomment if weighted undirected graph
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        for (auto x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

int32_t main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}