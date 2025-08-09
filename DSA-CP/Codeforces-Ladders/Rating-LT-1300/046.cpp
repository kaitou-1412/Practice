// B. Sale
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, res = 0;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for(int i=0; i<m; i++) {
        if(a[i]>0) break;
        res -= a[i];
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
