#include <bits/stdc++.h>
#define int long long

using namespace std;
signed solve(int a,int b,int k){
    if (b==0){
        return 1;
    }
    int value = solve(a,b/2,k);  
    if(b%2==0){
        return (value*value) % k;
    }else{
        return (((value*a) % k)*value)%k;
    }
}


signed main() {
    int a,b,k;

    cin >> a;  
    cin >> b;  
    cin >> k;  

    cout << solve(a,b,k);

    return 0;
}
