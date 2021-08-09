#include "bits/stdc++.h"
using namespace std;

typedef pair<long long, long long> ii;

const long long INF = 1e18 + 5;

int dijsktra(int N, int S, int T, vector<vector<ii> > &adj){
    vector<long long> d(N, INF);
    priority_queue<ii, vector<ii>, greater<ii> > prioQ;
    
    d[S] = 0;
    prioQ.push(make_pair(d[S], S));
    
    while(!prioQ.empty()){
        int u;
        ii x;

        x = prioQ.top();
        prioQ.pop();
        u = x.second;

        if(d[u] < x.first) {
            continue;
        }

        for(auto e : adj[u]) {
            long long w = e.second;
            int v = e.first;

            if(d[u] + w < d[v]) {
                d[v] = d[u] + w;
                prioQ.push(make_pair(d[v], v));
            }
        }
    }
    return ((d[T] == INF) ? -1 : d[T]);
}

int main(){
    int t;

    cin >> t;
    
    for(int k = 1; k <= t; k++){
        long long n, m, S, T;

        cin >> n >> m >> S >> T;

        vector<vector<ii> > adj(n);

        for(int i = 0; i < m; i++) {
            int u, v, w;

            cin >> u >> v >> w;
            
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }

        long long ans = dijsktra(n, S, T, adj);

        if(ans == -1) {
            printf("Case #%d: unreachable\n", k);
        }
        else {
            printf("Case #%d: %lld\n", k, ans);
        } 

        adj.clear();
    }

    return 0;
}