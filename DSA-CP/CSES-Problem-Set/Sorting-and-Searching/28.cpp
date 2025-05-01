// Stick Lengths
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int p[n];
    for(int i=0; i<n; i++) {
        cin >> p[i];
    }
    sort(p, p+n);
    int median = p[n/2];
    long long int res = 0;
    for(int i=0; i<n; i++) {
        res += abs(median - p[i]);
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