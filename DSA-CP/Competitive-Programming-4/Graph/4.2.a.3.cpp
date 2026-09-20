// Poor Trade Advisor
#include<bits/stdc++.h>
using namespace std;

void dfs(int u, int &res, vector<bool> &vis, vector<vector<int>> &adj) {
    vis[u] = true;
    res++;
    for(auto &v: adj[u]) {
        if(!vis[v]) {
            dfs(v, res, vis, adj);
        }
    }
}

int solve() {
    int n, m;
    cin >> n >> m;
    if(n == 0 && m == 0) return 0; 
    int u, v, w, max_w = INT_MIN;
    vector<vector<int>> edges;
    for(int i=0; i<m; i++) {
        cin >> u >> v >> w;
        max_w = max(max_w, w);
        edges.push_back({u, v, w});
    }
    vector<vector<int>> adj(n+1);
    for(auto &edge: edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        if(w == max_w) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    vector<bool> vis(n+1, false);
    int res = 0, count = 0;
    for(int i=1; i<=n; i++) {
        if(!vis[i] && !adj[i].empty()) {
            count = 0;
            dfs(i, count, vis, adj);
            res = max(res, count);
        }
    }
    cout << res << "\n";
    return 1;
}

int main() {
    int t = 1;
    while(t == 1) {
        t = solve();
    }
}
