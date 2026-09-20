// Where's My Internet??
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

int main() {
    long long int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis(n+1, false);
    dfs(1, vis, adj);
    bool connected = true;
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            connected = false;
            cout << i << "\n";
        }
    }
    if(connected) {
        cout << "Connected" << "\n";
    }
}