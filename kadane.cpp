#include <vector>
#include <iostream>
#define int long long
using namespace std;

vector<int> v;
int n;

int mss1() {
    int maksimum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int p = i; p <= j; p++) {
                sum += v[p];
            }
            maksimum = max(maksimum, sum);
        }
    }
    return maksimum;
}

int mss2() {
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + v[i - 1];
    }
    // for (int i = 0; i <= n; i++) {
    //     cout << prefix[i] << " ";
    // }
    // cout << endl;
    int maksimum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            maksimum = max(maksimum, prefix[j + 1] - prefix[i]);
        }
    }
    return maksimum;
}

int mss3() {
    int maksimum = 0;
    int current = 0;
    for (int i = 0; i < n; i++) {
        current += v[i];
        maksimum = max(maksimum, current);
        if (current < 0) current = 0;
    }
    return maksimum;
}

int32_t main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << mss1() << endl;
    cout << mss2() << endl;
    cout << mss3() << endl;
}