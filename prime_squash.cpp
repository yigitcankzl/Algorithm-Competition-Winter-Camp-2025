#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MAX_N = 1e7 + 1;
vector<bool> isPrime(MAX_N, true);

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < MAX_N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < MAX_N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();  

    int N, k;
    cin >> N >> k;
    vector<int> shirts(N);
    
    for (int i = 0; i < N; i++) {
        cin >> shirts[i];
    }

    unordered_map<int, int> primeCount; 
    int left = 0, right = 0, uniquePrimes = 0, validIntervals = 0;

    while (right < N) {
        int num = shirts[right];

        if (isPrime[num]) {
            if (primeCount[num] == 0) {
                uniquePrimes++;
            }
            primeCount[num]++;
        }

        while (uniquePrimes > k) {
            int leftNum = shirts[left];
            if (isPrime[leftNum]) {
                primeCount[leftNum]--;
                if (primeCount[leftNum] == 0) {
                    uniquePrimes--;
                }
            }
            left++;
        }

        validIntervals += (right - left + 1);
        right++;
    }

    cout << validIntervals << "\n";
    return 0;
}
