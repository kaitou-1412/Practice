// A. Magic Numbers
#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    string res = "YES";
    for(int i=0; i<n; i++) {
        if(s[i] == '1' && i+1<n && s[i+1] == '4' && i+2<n && s[i+2] == '4') {
            i += 2;
        } else if(s[i] == '1' && i+1<n && s[i+1] == '4') {
            i += 1;
        } else if(s[i] == '1') {
            continue;
        } else {
            res = "NO";
            break;
        }
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
