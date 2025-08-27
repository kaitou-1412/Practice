// A. Cookies
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int a, sum = 0, n, odd = 0;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a;
        if(a%2) odd++;
        sum += a;
    }
    cout << ((sum%2 == 1) ? odd : n-odd) << "\n";
}

int main() {
    solve();
    return 0;
}
