// B. Fun Permutation
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, p;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> p;
        cout << n+1-p << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}