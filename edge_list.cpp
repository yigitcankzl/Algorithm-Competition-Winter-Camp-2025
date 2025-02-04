#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    // vector<vector<int>> edges; // uncomment if weighted graph
    for (int i = 0; i < m; i++)
    {
        int u, v;
        // int weight; // uncomment if weighted graph
        cin >> u >> v;
        // cin >> weight; // uncomment if weighted graph
        edges.push_back({u, v});
        // edges.push_back({u, v, weight}); // uncomment if weighted graph
    }
    for (auto x : edges)
    {
        cout << x.first << " " << x.second << endl;
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