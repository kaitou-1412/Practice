// A. Reconnaissance 2
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, diff = INT_MAX, res;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) {
        if(abs(a[i] - a[(i+1)%n]) < diff) {
            diff = abs(a[i] - a[(i+1)%n]);
            res = i+1;
        }
    }
    cout << res << " " << (res+1>n ? 1 : (res+1)) << "\n";
}

int main() {
    solve();
    return 0;
}
