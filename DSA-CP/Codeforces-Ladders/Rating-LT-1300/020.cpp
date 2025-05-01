// A. Helpful Maths
#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s, res = "";
    cin >> s;
    vector<int> v;
    for(char ch: s) if(ch != '+') v.push_back(ch - '0');
    sort(v.begin(), v.end());
    res = to_string(v[0]);
    for(int i=1; i<v.size(); i++) res += "+" + to_string(v[i]);
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}