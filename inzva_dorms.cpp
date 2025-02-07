#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> capacities(n), prefix_sum(n);

    cin >> capacities[0];
    prefix_sum[0] = capacities[0];

    for (int i = 1; i < n; i++) {
        cin >> capacities[i];
        prefix_sum[i] = prefix_sum[i - 1] + capacities[i];
    }

    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;

        auto it = lower_bound(prefix_sum.begin(), prefix_sum.end(), p);

        if (it == prefix_sum.end()) {
            cout << -1 << "\n";  
        } else {
            cout << (it - prefix_sum.begin() + 1) << "\n";  
        }
    }

    return 0;
}
