// A. Football
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, wins = 1, wins2 = 0;
    cin >> n;
    string s, s2, s2real;
    cin >> s;
    n--;
    while(n--) {
        cin >> s2;
        if(s == s2) {
            wins++;
        } else {
            wins2++;
            s2real = s2;
        }
 
    }
    cout << (wins > wins2 ? s : s2real) << "\n";
}

int main() {
    solve();
    return 0;
}
