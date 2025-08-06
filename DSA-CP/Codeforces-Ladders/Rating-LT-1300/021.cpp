// A. Is your horseshoe on the other hoof?
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int s, res = 0;
    unordered_map<int, bool> mp;
    for(int i=0; i<4; i++) {
        cin >> s;
        if(!mp[s]) {
            res++;
            mp[s] = true;
        }
    }
    res = 4 - res;
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}