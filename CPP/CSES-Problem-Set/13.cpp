// Gray Code
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int r = (1 << n);
    for(int i=0; i<r; i++) {
        for(int j=n-1; j>=0; j--) {
            cout << ((1&(i>>(j+1)))^(1&(i>>j)));
        }
        cout << "\n";
    }
}
 
int main() {
    // int t;
    // cin >> t;
    // while(t--) solve();
    solve();
}