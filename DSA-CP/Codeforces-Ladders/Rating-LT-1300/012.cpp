// A. Ultra-Fast Mathematician
#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s1, s2, res = "";
    cin >> s1 >> s2;
    for(int i=0; i<s1.size(); i++) {
        if(s1[i] == s2[i]) res += "0";
        else res += "1";
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}