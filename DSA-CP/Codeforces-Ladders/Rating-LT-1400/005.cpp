// A. HQ9+
#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    cout << (
        s.find("H") != string::npos || 
        s.find("Q") != string::npos || 
        s.find("9") != string::npos ? "YES" : "NO"
    ) << "\n";
}

int main() {
    solve();
    return 0;
}
