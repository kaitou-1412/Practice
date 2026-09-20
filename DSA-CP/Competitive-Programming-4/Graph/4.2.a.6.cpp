// Reachable Roads
#include<bits/stdc++.h>
using namespace std;

void dfs(int u, vector<bool> &vis, vector<vector<int>> &adj) {
    vis[u] = true;
    for(int v: adj[u]) {
        if(!vis[v]) {
            dfs(v, vis, adj);
        }
    }
}

void solve(int case_number) {
    int n, m, u, v, res = 0;
    cin >> n;
    cin >> m;
    vector<vector<int>> adj(n);
    vector<bool> vis(n, false);
    for(int i=0; i<m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            res++;
            dfs(i, vis, adj);
        }
    }
    cout << (res-1) << "\n";
}

int main() {
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}
