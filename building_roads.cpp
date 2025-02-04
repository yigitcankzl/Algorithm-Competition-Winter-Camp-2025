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
    vector<int> dfs_started;
    stack<int> s;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
        {
            continue;
        }
        s.push(i);
        visited[i] = 1;
        dfs_started.push_back(i);
        while (s.size())
        {
            int curr = s.top();
            s.pop();
            for (int neighbor : adj[curr])
            {
                if (visited[neighbor])
                {
                    continue;
                }
                s.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << dfs_started.size() - 1 << "\n";
    for (int i = 0; i < dfs_started.size() - 1; i++)
    {
        cout << dfs_started[i] << " " << dfs_started[i + 1] << "\n";
    }
}

int32_t main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

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