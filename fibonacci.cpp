#include <vector>
#include <iostream>
#define int long long
using namespace std;

vector<int> v;

int fib(int n) {
    if (v[n] != -1) {
        return v[n];
    }
    if (n == 0) return 1;
    if (n == 1) return 1;
    return v[n] = fib(n - 1) + fib(n - 2);
}

int32_t main() {
    int n;
    cin >> n;
    v.resize(n + 1, -1);
    cout << fib(n) << endl;
}