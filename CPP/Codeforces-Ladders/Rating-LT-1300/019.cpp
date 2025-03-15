// A. Tram
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, curr = 0, res = 0, a, b;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        curr += b-a;
        res = max(res, curr);
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}