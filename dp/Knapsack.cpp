#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0)); // DP tablosu

    // DP tablosunu doldur
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W]; // Maksimum değeri döndür
}

int main() {
    int W = 50; // Çantanın kapasitesi
    vector<int> weights = {10, 20, 30}; // Öğelerin ağırlıkları
    vector<int> values = {60, 100, 120}; // Öğelerin değerleri
    int n = weights.size(); // Öğelerin sayısı

    cout << "Maksimum değer: " << knapsack(W, weights, values, n) << endl;
    return 0;
}
