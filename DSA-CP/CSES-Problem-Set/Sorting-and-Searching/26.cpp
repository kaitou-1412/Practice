// Sum of Two Values
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    int a[n];
    map<int, int> mp;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        mp[a[i]] = i+1;
    }
    int res1 = 0, res2 = 0;
    for(int i=0; i<n; i++) {
        if(mp[x-a[i]] != 0) {
            if(i+1 == mp[x-a[i]]) continue;
            res1 = i+1;
            res2 = mp[x-a[i]];
            break;
        }
    }
    if(res1 == 0 && res2 == 0) cout << "IMPOSSIBLE\n";
    else cout << res1 << " " << res2 << "\n";
}
 
int main() {
    // int t;
    // cin >> t;
    // while(t--) solve();
    ios_base::sync_with_stdio(false);
    solve();
}