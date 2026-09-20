// Dominoes 2
#include<bits/stdc++.h>
using namespace std;

void dfs(int u, int &res, vector<bool> &vis, vector<vector<int>> &adj) {
    vis[u] = true;
    res++;
    for(int v: adj[u]) {
        if(!vis[v]) {
            dfs(v, res, vis, adj);
        }
    }
}

void solve() {
    int n, m, l, u, v, root, res = 0;
    cin >> n >> m >> l;
    vector<vector<int>> adj(n+1);
    vector<bool> vis(n+1, false);
    for(int i=0; i<m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i=0; i<l; i++) {
        cin >> root;
        if(!vis[root]) {
            dfs(root, res, vis, adj);
        }
    }
    cout << res << "\n";
}

int main() {
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve();
}
