#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& topoSort) {
    visited[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, topoSort);
        }
    }

    topoSort.push(node);  // Düğüm işaretlendikten sonra sıralamaya ekle
}

void topologicalSort(int V, vector<vector<int>>& graph) {
    vector<bool> visited(V, false);
    stack<int> topoSort;

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfs(i, graph, visited, topoSort);
        }
    }

    cout << "Topolojik Sıralama: ";
    while (!topoSort.empty()) {
        cout << topoSort.top() << " ";
        topoSort.pop();
    }
    cout << endl;
}

int main() {
    int V = 6; // Düğüm sayısı
    vector<vector<int>> graph(V);

    // Grafın kenarlarını ekle
    graph[5].push_back(2);
    graph[5].push_back(0);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(1);

    topologicalSort(V, graph);

    return 0;
}