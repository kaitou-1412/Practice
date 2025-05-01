// Towers
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    multiset<int> towers;
    for(int i=0; i<n; i++) {
        if(towers.empty()) {
            towers.insert(a[i]);
        } else {
            auto top = towers.upper_bound(a[i]);
            if(top != towers.end()) {
                towers.erase(top);
            }  
            towers.insert(a[i]);
        }
    }
    int res = towers.size();
    cout << res << "\n";
}
 
int main() {
    // int t;
    // cin >> t;
    // while(t--) solve();
    ios_base::sync_with_stdio(false);
    solve();
}