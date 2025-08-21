// B. Jzzhu and Sequences
#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long int x, y, n, mod = 1000000007, res = 0;
    cin >> x >> y >> n;
    if(n%6 == 1) res = (x % mod + mod) % mod;
    else if(n%6 == 2) res = (y % mod + mod) % mod;
    else if(n%6 == 3) res = (y - x + mod) % mod;
    else if(n%6 == 4) res = (mod - x) % mod;
    else if(n%6 == 5) res = (mod - y) % mod;
    else if(n%6 == 0) res = (x - y + mod) % mod;
    cout << (res + mod) % mod << "\n";
}

int main() {
    solve();
    return 0;
}
