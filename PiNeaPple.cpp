#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   

    int m, n;
    cin >> m >> n;
    vector<int> normal(m);
    priority_queue<int, vector<int>, greater<int>> min_heap;


    for (int i = 0; i < m; i++) {
        cin >> normal[i];
        min_heap.push(normal[i]);

        if (min_heap.size() > min_heap.top()) {
            min_heap.pop();
        }

    }

    int h_index = min_heap.size(); 

    for (int j = 0; j < n; j++) {
        int new_citation;
        cin >> new_citation;
        min_heap.push(new_citation);

        if (min_heap.size() > min_heap.top()) {
            min_heap.pop();
        }

        h_index = min_heap.size();
        cout << h_index << endl;

    }
    return 0;
}
