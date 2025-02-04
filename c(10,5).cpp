#include <bits/stdc++.h>

using namespace std;
#define int long long

const int mod = 1e9 + 7;

// int factmod_old(int number, int mod) {
//     vector<int> fac(mod);
//     fac[0] = 1;
//     for (int i = 1; i < mod; i++)
//         fac[i] = fac[i-1] * i % mod;

//     int result = 1;

//     while (number > 1) {
//         if (((number/mod) % 2 ) == 1){
//             result = mod - result;
//         }
//         result = result * fac[number%mod] % mod;
//         number /= mod;
//     }
//     return result;
// }

int factmod(int number, int mod) {
    int result = 1;
    while (number > 1) {
        if (((number / mod) % 2) == 1) {
            result = mod - result;
        }
        
        for (int i = 2; i <= number % mod; i++) {
            result = (result * i) % mod;
        }
        
        number /= mod;
    }
    return result;
}

int power(int a, int b, int mod) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1)  
            result = (result * a) % mod;
        a = (a * a) % mod; 
        b /= 2;
    }
    return result%mod;
}


signed main() { 
    int a,b;
    cin >> a;  
    cin >> b;  


    int upper_part = factmod(a, mod);
    int lower_part = factmod(b, mod);
    int lower_part2 = factmod(a - b, mod);

    int lower_part_inv = power(lower_part, mod - 2, mod); 
    int lower_part2_inv = power(lower_part2, mod - 2, mod);

    int result = (upper_part * lower_part_inv % mod) * lower_part2_inv % mod;
    cout << result << endl;

    return 0;
}
