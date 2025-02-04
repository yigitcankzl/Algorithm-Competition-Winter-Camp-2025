//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
#define ll long long
#define N 100005

using namespace std;
vector<int> from(N, INT_MAX);
vector<pair<ll, ll>> adj[N];
priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll, ll>>> pq;

int main() {
// write your code here

    int n; cin >> n;
    int m; cin >> m;

    int distances[n + 1];
    vector<int> distfrom(n + 1, -1);

    distances[0] = 0;
    distances[1] = 0;

    for(int i = 0; i < m; i++){

        int n1; cin >> n1;
        int n2; cin >> n2;
        int w; cin >> w;

        if(n1 == n2){
            continue;
        }

        adj[n1].push_back(make_pair(n2, w));
        adj[n2].push_back(make_pair(n1, w));

    }

    for(int i = 2; i < n + 1; i++){

        vector<ll> dist(N, LLONG_MAX);
        int target; cin >> target;
        distfrom[i] = target; 

        dist[i] = 0;
        from[i] = -1;
        pq.push({0, i});

        while(!pq.empty()){
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

        int tds = dist[target];
        distances[i] = tds;

    }

    int fans; cin >> fans;

    for(int i = 0; i < fans; i++){

        int counter = 0;
        int fan; cin >> fan;
        while(distfrom[fan] != -1){

            counter += distances[fan];
            fan = distfrom[fan];

        }

        cout << counter << "\n";

    }

	return 0;
}
