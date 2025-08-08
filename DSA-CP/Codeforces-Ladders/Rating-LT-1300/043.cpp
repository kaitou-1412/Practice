// A. Translation
#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    cout << (s == t ? "YES" : "NO") << "\n";
}

int main() {
    solve();
    return 0;
}
