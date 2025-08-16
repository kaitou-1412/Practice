// B. Unlucky Ticket
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s1 = s.substr(0, n), s2 = s.substr(n, n);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    bool small = true, big = true;
    for(int i=0; i<n; i++) {
        if(s1[i]>=s2[i]) {
            small = false;
            break;
        }
    }
    for(int i=0; i<n; i++) {
        if(s1[i]<=s2[i]) {
            big = false;
            break;
        }
    }
    cout << (small || big ? "YES" : "NO") << "\n";
}

int main() {
    solve();
    return 0;
}
