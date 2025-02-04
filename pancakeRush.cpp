//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

vector<pair<ll,ll>> adj[N];
vector<ll> even(N, LLONG_MAX);
vector<ll> odd(N, LLONG_MAX);
priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;

int main() {
// write your code here
    ll n, m;
    cin>>n>>m;
    
    for (int i = 1; i <= m; i++) {
        ll u, v, w;
        cin>>u>>v>>w;
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    even[1] = 0;
    pq.push({0, {1, 0}});
    
    while( !pq.empty()) {
        ll node = pq.top().second.first;   
        ll dis = pq.top().first;
        ll state = pq.top().second.second;
        
        pq.pop();
        
        for (pair<ll, ll> p : adj[node]) {
            ll v = p.first;
            ll w = p.second;
            
            if (state == 0) {
                if (even[node] + 2*w < odd[v]) {
                    odd[v] = even[node] + 2*w;
                    pq.push({odd[v], {v, 1}});
                }
            }
        
            else {
                if (odd[node] + w/2 < even[v]) {
                    even[v] = odd[node] + w/2;
                    pq.push({even[v], {v, 0}});
                }
            }
        }
    }
    
    cout<<min(even[n], odd[n]);
    
	return 0;
}
