// A. Team
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, res = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b + c >= 2) res++;
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
