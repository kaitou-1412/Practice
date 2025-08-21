// B. T-primes
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long a, b, j;
    for(int i=0; i<n; i++) {
        cin >> a;
        b = sqrt(a);
        for(j=2; j*j<=b; j++) if(b%j == 0) break;
        if(a>=2 && j*j>b && b*b == a) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    solve();
    return 0;
}
