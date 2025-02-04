//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
#define ll long long
#define N 100005

using namespace std;

vector<ll> dist(N, LLONG_MAX);
vector<int> from(N, INT_MAX);
vector<int> order;
vector<pair<ll, ll>> adj[N];  
// [vector<pair<ll,ll>>, vector<pair<ll,ll>>, vector<pair<ll,ll>>, ...]
priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll, ll>>> pq;

int main() {
// write your code here
    ll n, m;
    cin>>n>>m;
    
    for (int i = 1; i <= m; i++) {
        ll u, v, w;
        cin>>u>>v>>w;
        
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    
    dist[n] = 0;
    from[n] = -1;
    pq.push({0, n});
    
    while (! pq.empty()) {
        ll u = pq.top().second;
        ll dis = pq.top().first;
        pq.pop();
        
        for (auto child : adj[u]) {
            ll v = child.first;
            ll w = child.second;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                from[v] = u;
            }
            
            if (dist[u] + w == dist[v]) {
                if (u < from[v]) {
                    from[v] = u;
                }
            }
        }
    }
    
    if (dist[1] == LLONG_MAX) {
        cout<<-1;
        return 0;
    }
    
    int path = 1;
    
    while (path != -1) {
        order.push_back(path);
        path = from[path];
    }
    
    for (int i = 0; i < order.size(); i++) {
        cout<<order[i]<<" ";
    }
	return 0;
}
