// B. Xenia and Ringroad
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, a, prev = 1;
    long long int res = 0;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> a;
        res += (prev <= a) ? (a - prev) : (n + a - prev);
        prev = a;
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
