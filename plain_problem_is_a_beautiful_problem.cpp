#include <iostream>
#include <vector>

#define int long long
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> numbers(N);

    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    int counter = 0;
    int odd_count = 0, even_count = 0;

    for (int i = 0; i < N; i++) {
        if (i > K) {
            if (numbers[i - K - 1] % 2 == 0) {
                even_count--;
            } else {
                odd_count--;
            }
        }

        if (numbers[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }

        if (numbers[i] % 2 == 0) {
            counter += odd_count;  
        } else {
            counter += even_count;
        }
    }

    cout << counter << '\n';
    return 0;
}
