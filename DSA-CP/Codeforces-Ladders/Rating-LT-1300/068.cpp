// B. Letter
#include<bits/stdc++.h>
using namespace std;

void solve() {
    string h, t, res = "YES";
    getline(cin, h); 
    getline(cin, t);
    unordered_map<char, int> mp; 
    for(int i=0; i<h.size(); i++) {
        if(h[i] == ' ') continue;
        mp[h[i]]++;
    }
    for(int i=0; i<t.size(); i++) {
        if(t[i] == ' ') continue;
        mp[t[i]]--;
        if(mp[t[i]]<0) {
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
