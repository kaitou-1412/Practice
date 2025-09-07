// A. Collatz Conjecture
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int k, x;
    cin >> k >> x;
    while(k--) {
        if((x-1)%3 == 0 && ((x-1)/3)%2 == 1) x = (x-1)/3;
        else x *= 2;
    }
    cout << x << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}