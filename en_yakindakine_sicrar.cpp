#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> q;
    stack<int> s_cikan;
    unordered_set<int> oyunda;

    for (int i = 0; i < n; ++i) {
        string event;
        cin >> event;

        if (event == "-") {
            if (!q.empty()) {
                int cikan = q.front();
                q.pop();
                s_cikan.push(cikan);
            }
        } else if (event == "+") {
            if (!s_cikan.empty()) {
                int giren = s_cikan.top();
                s_cikan.pop();
                q.push(giren);
            }
        } else {
            int player = stoi(event);
            if (oyunda.find(player) == oyunda.end()) {
                oyunda.insert(player);
                q.push(player);
            }
        }
    }

    vector<int> result;
    while (!q.empty()) {
        result.push_back(q.front());
        q.pop();
    }
    reverse(result.begin(), result.end());
    
    for (size_t i = 0; i < result.size(); ++i) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}
