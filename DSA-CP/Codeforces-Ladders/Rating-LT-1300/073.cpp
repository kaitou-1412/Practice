// A. Little Elephant and Bits
#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    bool f = false;
    for(int i=0; i<s.size(); i++) {
        if(!f && s[i] == '0') {
            f = true;
        } else if(!f && i+1 == s.size()) {
            break;
        } else {
            cout << s[i];
        }
    }
    cout << "\n";
}

int main() {
    solve();
    return 0;
}
