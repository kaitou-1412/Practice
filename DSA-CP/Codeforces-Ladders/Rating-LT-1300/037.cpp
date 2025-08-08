// A. Even Odds
#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long int n, k;
    cin >> n >> k;
    long long int v = ceil(n*1.0/2);
    if(k <= v)
        cout << (2*k -1) << "\n";
    else {
        k -= v;
        cout << (2*k) << "\n";
    }
}

int main() {
    solve();
    return 0;
}
