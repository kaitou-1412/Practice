// A. Football
#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s, res = "NO";
    cin >> s;
    char prev = ' ', count = 0;
    for(char ch: s) {
        if(ch != prev) count = 0;
        count++;
        prev = ch;
        if(count>=7) {
            res = "YES";
            break;
        } 
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
