// Josephus Problem I
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    set<int> s;
    for(int i=1; i<=n; i++) {
        s.insert(i);
    }
    auto it = s.begin();
    for(int i=0; i<n; i++) {
        it++;
        if(it == s.end()) it = s.begin();
        cout << *it << " ";
        auto itnext = next(it);
        s.erase(it);
        if(itnext == s.end()) itnext = s.begin();
        it = itnext;
    }
}
 
int main() {
    // int t;
    // cin >> t;
    // while(t--) solve();
    ios_base::sync_with_stdio(false);
    solve();
}