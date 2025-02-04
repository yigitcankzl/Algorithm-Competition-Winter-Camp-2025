#include <bits/stdc++.h>
using namespace std;

void printvec(const vector<int>& vec) {
    for (int x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> sorted_a;
    for (int i = 0; i < n; i++) {
        sorted_a.push_back({a[i], i + 1});
    }

    sort(sorted_a.begin(), sorted_a.end());

    vector<int> location1(n);
    for (int i = 0; i < n; i++) {
        location1[i] = sorted_a[i].second;
    }

    vector<int> location2(n);
    for (int i = 0; i < n; i++) {
        location2[sorted_a[i].second - 1] = i + 1;
    }

    if (m == 0) {
        printvec(a);
    } else if (m % 2 == 1) {
        printvec(location1);
    } else {
        printvec(location2);
    }

    return 0;
}
