#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii; // (Ağırlık, Düğüm)

// Prim Algoritması
void prim(int n, vector<vector<pii>> &graph) {
    vector<bool> visited(n, false); // Ziyaret edilen düğümleri takip et
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min Heap (Ağırlık, Düğüm)
    vector<pii> mst; // MST'yi saklayan vektör

    pq.push({0, 0}); // Başlangıç düğümü (Ağırlık, Düğüm)

    while (!pq.empty() && mst.size() < n - 1) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        if (u != 0) { // İlk düğüm hariç MST'ye ekle
            mst.push_back({u, weight});
        }

        for (auto &[w, v] : graph[u]) {
            if (!visited[v]) {
                pq.push({w, v});
            }
        }
    }

    cout << "Minimum Spanning Tree:\n";
    for (auto &[node, weight] : mst) {
        cout << "Node: " << node << ", Weight: " << weight << endl;
    }
}

int main() {
    int n = 5; // Düğüm sayısı
    vector<vector<pii>> graph(n);

    // Grafın kenarlarını ekle
    graph[0].push_back({2, 1});
    graph[0].push_back({3, 3});
    graph[1].push_back({2, 0});
    graph[1].push_back({4, 2});
    graph[2].push_back({4, 1});
    graph[2].push_back({1, 3});
    graph[3].push_back({3, 0});
    graph[3].push_back({1, 2});
    graph[3].push_back({5, 4});
    graph[4].push_back({5, 3});

    prim(n, graph);

    return 0;
}