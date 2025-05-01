// Distinct Numbers
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int x;
    map<int, int> mp;
    for(int i=0; i<n; i++) {
        cin >> x;
        mp[x]++;
    }
    int res = mp.size();
    cout << res << "\n";
}
 
int main() {
    // int t;
    // cin >> t;
    // while(t--) solve();
    ios_base::sync_with_stdio(false);
    solve();
}