// Maximum Subarray Sum
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    long long int curr = 0, res = LLONG_MIN;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        if(a[i] <= curr + a[i]) {
            curr += a[i];
        } else {
            curr = a[i];
        }
        res = max(res, curr);
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