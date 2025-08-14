// A. Shooshuns and Sequence
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, res = 0;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=n-1; i>0; i--) {
        if(a[i]!=a[i-1]) {
            res = i;
            break;
        }
    }
    if(res>=k) res = -1; 
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
