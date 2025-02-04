#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e7;


vector<int> prime(MAX_N +1, 0);

void sieve(){
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i] == 0) {
            for (int j = i; j <= MAX_N; j += i) {
                if (prime[j] == 0)
                    prime[j] = i;
            }
        }
    }
}

    
int count_distinct_primes(int x) {
    unordered_set<int> primes;
    while (x > 1) {
        primes.insert(prime[x]);
        x /= prime[x];
    }
    return primes.size();
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    int n;
    cin >> n;


    while (n--) { 
        int a, b;
        cin >> a >> b;  
        int ebob = gcd(a, b);
        count_distinct_primes(a);
        count_distinct_primes(b);
        count_distinct_primes(ebob);
        cout << count_distinct_primes(a) + count_distinct_primes(b) - count_distinct_primes(ebob) << "\n";
      }
	return 0;
}