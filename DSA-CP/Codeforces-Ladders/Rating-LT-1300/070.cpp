// A. Comparing Strings
#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s1, s2, res = "NO";
    cin >> s1 >> s2;
    if(s1.size() == s2.size()) {
        vector<int> v;
        for(int i=0; i<s1.size(); i++) {
            if(s1[i]!=s2[i]) v.push_back(i);
            if(v.size()>2) break;
        }
        if(v.size() == 2 && s1[v[0]] == s2[v[1]] && s1[v[1]] == s2[v[0]]) res = "YES";
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
