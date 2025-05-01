// Missing Coin Sum
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int x[n];
    for(int i=0; i<n; i++) {
        cin >> x[i];
    }
    sort(x, x+n);
    long long int res = 1;
    for(int i=0; i<n && x[i] <= res; i++) {
        res += x[i];
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