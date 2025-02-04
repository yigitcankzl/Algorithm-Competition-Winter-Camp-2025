#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n) {
    vector<int> dp(n + 1, 0); // DP tablosu, başlangıçta tüm değerler 0.
    dp[0] = 0; // F(0)
    dp[1] = 1; // F(1)

    // DP tablosunda Fibonacci sayılarını hesapla
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n]; // Sonucu döndür
}

int main() {
    int n;
    cout << "Fibonacci için n'i girin: ";
    cin >> n;

    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}
