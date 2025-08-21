// B. Kuriyama Mirai's Stones
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, type, l, r;
    cin >> n;
    vector<long long int> v(n), a(n), sum1(n+1, 0), sum2(n+1, 0);
    for(int i=0; i<n; i++) {
        cin >> v[i];
        a[i] = v[i]; 
    }
    sort(a.begin(), a.end());
    for(int i=1; i<=n; i++) {
        sum1[i] = sum1[i-1] + v[i-1];
        sum2[i] = sum2[i-1] + a[i-1];
    }
    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> type >> l >> r;
        long long int res = (type == 1) ? (sum1[r] - sum1[l-1]) : (sum2[r] - sum2[l-1]);
        cout << res << "\n";
    }
}

int main() {
    solve();
    return 0;
}
