// A. Boy or Girl
#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    unordered_map<char, bool> mp;
    for(char ch: s) mp[ch] = true;
    int unique_count = mp.size();
    cout << (unique_count % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!") << "\n";
}

int main() {
    solve();
    return 0;
}
