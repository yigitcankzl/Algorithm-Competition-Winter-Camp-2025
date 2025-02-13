#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class UnionFind {
    vector<int> parent, rank;
public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for(int i = 0; i < size; i++) 
            parent[i] = i;
    }
    
    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return false;
        
        if(rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if(rank[px] == rank[py]) rank[px]++;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<pair<ll, pair<int, int>>> edges;
    
    for(int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    
    sort(edges.begin(), edges.end());
    
    UnionFind uf(n + 1);  
    ll total_weight = 0;
    int edges_used = 0;
    
    for(auto &edge : edges) {
        ll weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        
        if(uf.unite(u, v)) {
            total_weight += weight;
            edges_used++;
            if(edges_used == n - 1) break;  
        }
    }
    
    cout << total_weight << "\n";
    
    return 0;
}