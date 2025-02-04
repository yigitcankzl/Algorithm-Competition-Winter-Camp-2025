#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n + 1, false);
    stack<int> s;
    s.push(1);
    visited[1] = true;
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        cout << node << " ";
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                s.push(it);
                visited[it] = true;
            }
        }
    }
    cout << endl;
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