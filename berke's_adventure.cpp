#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int dijkstra(int N, const vector<vector<pii>>& graph, int start, int end) {
    vector<int> distances(N + 1, INT_MAX);
    distances[start] = 0;
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();
        
        if (current_node == end) {
            return current_dist;
        }
        
        if (current_dist > distances[current_node]) {
            continue;
        }
        
        for (const auto& neighbor : graph[current_node]) {
            int neighbor_node = neighbor.first;
            int edge_weight = neighbor.second;
            int new_dist = current_dist + edge_weight;
            
            if (new_dist < distances[neighbor_node]) {
                distances[neighbor_node] = new_dist;
                pq.push({new_dist, neighbor_node});
            }
        }
    }
    
    return -1;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    int U, V;
    cin >> U >> V;
    
    vector<vector<pii>> graph(N + 1);
    
    for (int i = 0; i < M; i++) {
        int X, Y, W;
        cin >> X >> Y >> W;
        graph[X].push_back({Y, W});
        graph[Y].push_back({X, W});
    }
    
    int result = dijkstra(N, graph, U, V);
    
    cout << result << endl;
    
    return 0;
}
