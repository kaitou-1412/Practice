// A. The number of positions
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b, res = 0;
    cin >> n >> a >> b;
    res = n + 1 - max(a+1, n-b);
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
