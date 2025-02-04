#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
vector<vector<int>> adj;
vector<int> parent;
vector<int> visited;
bool cycle_found = false;
vector<int> cycle_path;

void dfs(int u, int par)
{
    if (cycle_found)
        return;
    visited[u] = 1;
    parent[u] = par;

    for (auto &v : adj[u])
    {
        if (v == par)
            continue;
        if (!visited[v])
        {
            dfs(v, u);
            if (cycle_found)
                return;
        }
        else
        {
            cycle_found = true;
            cycle_path.push_back(v);
            int current = u;
            while (current != v)
            {
                cycle_path.push_back(current);
                current = parent[current];
            }
            cycle_path.push_back(v);
            return;
        }
    }
}

void solve()
{
    cin >> n >> m;
    adj.assign(n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    parent.assign(n + 1, -1);
    visited.assign(n + 1, 0);
    cycle_found = false;
    cycle_path.clear();

    for (int start = 1; start <= n && !cycle_found; start++)
    {
        if (!visited[start])
        {
            dfs(start, -1);
        }
    }

    if (cycle_found)
    {
        cout << cycle_path.size() << "\n";
        for (auto &node : cycle_path)
        {
            cout << node << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
}

int32_t main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--)
    {
        solve();
    }
}
