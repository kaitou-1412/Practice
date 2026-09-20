// Graph Connectivity
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

string trim(string s) {
    while(!s.empty() && isspace((unsigned char)s.back())) s.pop_back();
    int i = 0;
    while(i < (int)s.size() && isspace((unsigned char)s[i])) i++;
    return s.substr(i);
}

void solve() {
    string line;
    // skip the blank line(s) before the node name
    while(getline(cin, line)) {
        line = trim(line);
        if(!line.empty()) break;
    }
    int n = line[0] - 'A' + 1;
    vector<vector<int>> adj(n+1);
    while(getline(cin, line)) {
        line = trim(line);
        if(line.empty()) break;
        int u = line[0] - 'A' + 1;
        int v = line[1] - 'A' + 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n+1, false);
    int res = 0;
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            res++;
            dfs(i, vis, adj);
        }
    }
    cout << res << "\n";
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        solve();
        if(t) cout << "\n";
    }
}
