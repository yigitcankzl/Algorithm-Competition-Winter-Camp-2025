#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;
unordered_map<int,int> dpf,dpg,dph;

int f(int n);
int g(int n);

int h(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 0;
    if(dph.count(n) > 0) return dph[n];
    return dph[n] = (f(n-1) + h(n-3))%MOD;
}

int g(int n){
    if(n == 0) return 0;
    if(n == 1) return 0;
    if(n == 2) return 1;
    if(dpg.count(n) > 0) return dpg[n];
    return dpg[n] = (g(n-3)+ h(n-1))%MOD;
}

int f(int n){
    if(n == 0) return 1;
    if(n == 1) return 0;
    if(n == 2) return 0;
    if(dpf.count(n) > 0) return dpf[n];
    return dpf[n] = ((2*g(n-1))%MOD + f(n-3))%MOD;
}


int32_t main(){
    int n;
    cin >> n;
    cout << f(n) << endl;
}