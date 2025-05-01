// Collecting Numbers II
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, a, b;
    cin >> n >> m;
    int x[n+1], pos[n+1];
    for(int i=1; i<=n; i++) {
        cin >> x[i];
        pos[x[i]] = i;
    }
    int res = 1;
    for(int num=1; num<n; num++) {
        if(pos[num] > pos[num+1]) {
            res++;
        }
    }
    set<pair<int, int>> p;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        if(x[a]+1 <= n) p.insert({x[a], x[a]+1});
        if(x[a]-1 >= 1) p.insert({x[a]-1, x[a]});
        if(x[b]+1 <= n) p.insert({x[b], x[b]+1});
        if(x[b]-1 >= 1) p.insert({x[b]-1, x[b]});
        for(auto pit: p) {
            if(pos[pit.first]>pos[pit.second]) {
                res--;
            } 
        }
        swap(x[a], x[b]);
        pos[x[a]] = a;
        pos[x[b]] = b;
        for(auto pit: p) {
            if(pos[pit.first]>pos[pit.second]) {
                res++;
            } 
        }
        cout << res << "\n";
        p.clear();
    }
}
 
int main() {
    // int t;
    // cin >> t;
    // while(t--) solve();
    ios_base::sync_with_stdio(false);
    solve();
}