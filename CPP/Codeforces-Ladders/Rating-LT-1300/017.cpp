// A. Cupboards
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, res = 0, l, r, l_open = 0, r_open = 0;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> l >> r;
        if(l) l_open++;
        if(r) r_open++;
    }
    int l_closed = n - l_open, r_closed = n - r_open;
    res += (l_open<l_closed) ? l_open : l_closed;
    res += (r_open<r_closed) ? r_open : r_closed;
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}