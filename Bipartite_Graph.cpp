#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(int V, vector<vector<int>>& graph) {
    vector<int> color(V, -1);  // -1: renklenmemiş, 0: kırmızı, 1: mavi
    queue<int> q;

    // Her bir bileşen için kontrol et
    for (int i = 0; i < V; ++i) {
        if (color[i] == -1) {  // Renklenmemiş düğüm
            color[i] = 0;  // Başlangıç rengi
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                    if (color[neighbor] == -1) {  // Renklenmemiş komşu
                        color[neighbor] = 1 - color[node];  // Farklı renk ver
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false;  // Aynı renk, bipartite değil
                    }
                }
            }
        }
    }

    return true;  // Bipartite graf
}

int main() {
    int V = 4;
    vector<vector<int>> graph(V);

    graph[0].push_back(1);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(2);

    if (isBipartite(V, graph))
        cout << "Graf bipartite!" << endl;
    else
        cout << "Graf bipartite değil!" << endl;

    return 0;
}
