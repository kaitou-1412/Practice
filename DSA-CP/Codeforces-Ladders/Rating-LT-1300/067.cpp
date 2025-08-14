// A. Xenia and Divisors
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, a;
    cin >> n;
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++) {
        cin >> a;
        mp[a]++;
    }
    int o136 = 0, o126 = 0, o124 = 0;
    while(mp[6]>0 && mp[3]>0 && mp[1]>0) {
        mp[6]--;
        mp[3]--;
        mp[1]--;
        o136++;
    }
    while(mp[6]>0 && mp[2]>0 && mp[1]>0) {
        mp[6]--;
        mp[2]--;
        mp[1]--;
        o126++;
    }
    while(mp[4]>0 && mp[2]>0 && mp[1]>0) {
        mp[4]--;
        mp[2]--;
        mp[1]--;
        o124++;
    }
    if(o124 + o126 + o136 != n/3 || mp[5] || mp[7]) {
        cout << "-1\n";
        return;
    }
    while(o124--) cout << "1 2 4\n";
    while(o126--) cout << "1 2 6\n";
    while(o136--) cout << "1 3 6\n";
}

int main() {
    solve();
    return 0;
}
