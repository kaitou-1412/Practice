// A. Perfect Permutation
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if(n%2) {
        cout << "-1\n";
        return;
    }
    for(int i=1; i<=n; i++) {
        if(i%2) cout << i+1 << " ";
        else if(i == n) cout << i-1 << "\n";
        else cout << i-1 << " ";
    }
}

int main() {
    solve();
    return 0;
}