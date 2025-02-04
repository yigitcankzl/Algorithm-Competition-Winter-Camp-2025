//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
#include <cstdint>
#define int long long


using namespace std;

int MAX_N = 1e6 + 1;


void sieve(int n, vector<bool> &isPrimeArray){
    isPrimeArray[0] = false, isPrimeArray[1] = false;
    for(int i = 2; i*i < n; i++){

        if(isPrimeArray[i])
        for(int j = i*2; j < n; j += i)
        isPrimeArray[j] = false;

    }
    
 }

int32_t main() {
// write your code here

    vector<bool> prime(MAX_N, true);

    int k, l;
    cin >> k >> l;
    
    sieve(MAX_N, prime);
    
    int counter = 0;
    int sum = 0;

    for(int i = k; i <= l; i++){

        if(prime[i] == true){
            counter++;
            sum += i;
        }

    }

    cout << counter << " " << sum;

	return 0;
}
