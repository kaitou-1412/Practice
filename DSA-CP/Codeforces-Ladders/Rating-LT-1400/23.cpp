// Concert Tickets
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int h, t;
    multiset<int> p;
    for(int i=0; i<n; i++) {
        cin >> h;
        p.insert(h);
    }
    for(int i=0; i<m; i++) {
        cin >> t;
        if(p.empty()) {
            cout << "-1\n";
            continue;
        }
        auto it = p.lower_bound(t);
        if(it == p.begin() && *it > t) {
            cout << "-1\n";
            continue;
        }
        if(it == p.end() || *it > t) it--;
        cout << *it << "\n";
        p.erase(it);
    }
}
 
int main() {
    // int t;
    // cin >> t;
    // while(t--) solve();
    ios_base::sync_with_stdio(false);
    solve();
}