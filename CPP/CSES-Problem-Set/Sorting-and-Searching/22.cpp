// Ferris Wheel
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, ele;
    cin >> n >> x;
    multiset<int> p; 
    for(int i=0; i<n; i++) {
        cin >> ele;
        p.insert(ele);
    }
    int res = 0, target = 0;
    while(!p.empty()) {
        if(target == 0) {
            res++;
            target = x - *p.begin();
            p.erase(p.begin());
        } else {
            auto it = p.lower_bound(target);
            if(it == p.begin() && *it > target) {
                target = x - *it;
                p.erase(it);
                res++;
                continue;
            }
            if(it == p.end() || *it > target) {
                it--;
            }
            target = 0;
            p.erase(it);
        }
    }
    cout << res << "\n";
}
 
int main() {
    // int t;
    // cin >> t;
    // while(t--) solve();
    ios_base::sync_with_stdio(false);
    solve();
}