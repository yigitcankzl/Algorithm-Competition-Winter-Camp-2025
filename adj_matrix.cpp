#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // int weight; // uncomment if weighted graph
        adj[u][v] = 1;
        adj[v][u] = 1; // comment if directed
        // adj[u][v] = weight; // uncomment if weighted graph
        // adj[v][u] = weight; // uncomment if weighted undirected graph
    }
    cout << " | ";
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "-|";
    for (int i = 1; i <= n; i++)
    {
        cout << "——";
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << "| ";
        for (int j = 1; j <= n; j++)
        {
            cout << adj[i][j] << " ";
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