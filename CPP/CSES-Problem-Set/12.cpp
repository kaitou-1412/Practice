// Palindrome Reorder
#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s, res = "";
    cin >> s;
    vector<int> count(26, 0);
    for(int i=0; i<(int)s.size(); i++) count[s[i] - 'A']++;
    int odd = 0;
    for(int i=0; i<26; i++) {
        if(count[i]%2) {
            odd++;
            res += (char)('A' + i);
            count[i]--;
        }
    }
    if(odd <= 1) {
        for(int i=0; i<26; i++) {
            count[i] /= 2;
            char ch = (char)('A' + i);
            res.insert(0, count[i], ch);
            res.append(count[i], ch);
        }
        cout << res << "\n";
    } else {
        cout << "NO SOLUTION\n";
    }
}
 
int main() {
    // int t;
    // cin >> t;
    // while(t--) solve();
    solve();
}