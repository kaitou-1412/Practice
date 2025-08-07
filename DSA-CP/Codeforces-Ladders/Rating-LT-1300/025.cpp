// A. Soft Drinking
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int drink = k*l, lime = c*d, toasts = 0;
    while(drink >= n*nl && lime >= n && p >= n*np) {
        toasts++;
        drink -= n*nl;
        lime -= n;
        p -= n*np;
    }
    cout << toasts << "\n";
}

int main() {
    solve();
    return 0;
}
