// A. Way Too Long Words
#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    if(n<=10) {
        cout << s << "\n";
    } else {
        cout << s[0] << (n-2) << s[n-1] << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
