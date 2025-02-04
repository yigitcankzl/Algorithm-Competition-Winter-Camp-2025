#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> Edge;
#define pb push_back

int main(){
    ios::sync_with_stdio(0); cin.tie(0); // Faster I/O with cin & cout
    int n, m; cin >> n >> m;
    vector<vector<Edge>> g(n+1);
    while(m--){
        int u, v, w; cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    vector<bool> added(n+1, 0);
    ll mst_weight = 0;
    // prim_q stores {edge weight, unexplored node connected to edge}
    priority_queue<vector<int>> prim_q;
    prim_q.push({0, 1});
    while(!prim_q.empty()){
        auto edge = prim_q.top();
        prim_q.pop();
        int w = -edge[0];
        int cur = edge[1];
        if(added[cur]) continue;
        added[cur] = true;
        mst_weight += w;
        for(Edge edge: g[cur]){
            int nxt = edge[0];
            int w = edge[1];
            if(!added[nxt]) // not required but optimizes the algorithm a bit
                prim_q.push({-w, nxt});
        }
    }
    cout << mst_weight;
}
