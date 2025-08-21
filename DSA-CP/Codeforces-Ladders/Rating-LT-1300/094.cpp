// A. Free Cash
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int curr1, curr2, res = 0;
    unordered_map<int, unordered_map<int, int>> mp;
    for(int i=0; i<n; i++) {
        cin >> curr1 >> curr2;
        mp[curr1][curr2]++;
        res = max(res, mp[curr1][curr2]);
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
