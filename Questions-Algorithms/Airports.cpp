#include "bits/stdc++.h"
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int root[20000], sz[20000];

int find(int a) {
    if(root[a] == a) {
        return a;
    }
    return root[a] = find(root[a]);
}

void join(int a, int b) {
    a = find(a);
    b = find(b);

    if(a != b) {
        if(sz[a] < sz[b]) {
            root[b] = a;
        }
        else {
            root[a] = b;
        }

        sz[a] += sz[b];
        sz[b] += sz[a];
    }
}

int main(){
    int t;
    cin >> t;

    for(int k = 1; k <= t; k++) {
        int n, m, a;
        int mst = 0, ans = 0;
        priority_queue<iii, vector<iii>, greater<iii> > pq;

        cin >> n >> m >> a;

        for(int i = 0; i <= n; i++) {
            root[i] = i;
            sz[i] = 0;
        }

        for(int i = 0 ; i < m; i++) {
            int u, v, w;

            cin >> u >> v >> w;

            if(w < a) {
                pq.push(make_pair(w, make_pair(u, v)));
            } 
        }

        while(!pq.empty()) {
            int u, v, w;

            w = pq.top().first, u = pq.top().second.first, v = pq.top().second.second; 
            pq.pop();

            if(find(u) != find(v)) {
                mst += w;
                join(u, v);
            }
        }

        for(int i = 1; i <= n; i++) {
            find(i);

            if(root[i] == i) {
                ans++;
            }
        }

        printf("Case #%d: %d %d\n", k, mst + ans*a, ans); 
    }

    return 0;
}