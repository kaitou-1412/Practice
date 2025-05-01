#include<bits/stdc++.h>
using namespace std;

int main() {
    // A. Draw a Square
    int t;
    cin >> t;
    while(t--) {
        int l, r, d, u;
        cin >> l >> r >> d >> u;
        string res = (l == r && r == d && d == u && u == l) ? "Yes" : "No";
        cout << res << "\n";
    }
}