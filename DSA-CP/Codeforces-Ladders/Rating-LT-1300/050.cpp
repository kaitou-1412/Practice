// A. k-String
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int k;
    cin >> k;
    string s, res = "";
    cin >> s;
    vector<int> mp(26, 0);
    for(int i=0; i<s.size(); i++) mp[s[i] - 'a']++;
    for(int i=0; i<26; i++) {
        if(mp[i]%k != 0) {
            res = "-1";
            break;
        }
        string result_string(mp[i]/k, (char)(i + 'a'));
        res += result_string;
    }
    string rep = res;
    if(rep != "-1") for(int i=1; i<k; i++) res += rep;
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
