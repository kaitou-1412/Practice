// A. Bit++
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, res = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.find("++") != string::npos) res++;
        else if (s.find("--") != string::npos) res--;
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
