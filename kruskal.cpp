#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Disjoint Set veri yapısı (Union-Find)
class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if (parent[v] != v) {
            parent[v] = find(parent[v]); // Path compression
        }
        return parent[v];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    DisjointSet ds(n);
    int mst_weight = 0;
    for (const Edge& edge : edges) {
        if (ds.find(edge.u) != ds.find(edge.v)) {
            ds.unite(edge.u, edge.v);
            mst_weight += edge.weight;
            cout << "Edge (" << edge.u << ", " << edge.v << ") with weight " << edge.weight << " included in MST." << endl;
        }
    }
    return mst_weight;
}

int main() {
    int n = 4; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int mst_weight = kruskal(n, edges);
    cout << "Weight of MST is " << mst_weight << endl;

    return 0;
}