#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int nv, na;

    while(cin >> nv >> na && (nv != 0 || na != 0)){
        int a, b;

        vector<int> ans;
        vector<int> dep(nv, 0);
        vector<vector<int> > adj(nv);
        queue<int> fila;
        
        for(int i = 0; i < nv; i++) {
            cin >> a >> b;
            a--;
            b--;
            adj[a].push_back(b);
            dep[b]++;
        }

        for(int i = 0; i < nv; i++) {
            if(dep[i] == 0) {
                fila.push(i);
            }
        }

        while(!fila.empty()) {
            int curr = fila.front();
            fila.pop();
            ans.push_back(curr);

            for(int to: adj[curr]) {
                dep[to]--;

                if(dep[to] == 0) {
                    fila.push(to);
                }
            }
        }

        int size = ans.size();
        
        if(size < nv){
            cout << "IMPOSSIBLE\n";
        }
        else{
            for(int i = 0; i < size; i++) {
                cout << ans[i] + 1 << "\n";
            }
        }
    }
}