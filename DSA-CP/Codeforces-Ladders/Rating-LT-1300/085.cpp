// A. Cinema Line
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, res = 1;
    cin >> n;
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++) {
        cin >> a;
        if(a == 25) {
            mp[25]++;
        } else if(a == 50) {
            mp[50]++;
            if(mp[25]>0) {
                mp[25]--;
            } else {
                res = 0;
            }
        } else if(a == 100) {
            mp[100]++;
            if(mp[50]>0 && mp[25]>0) {
                mp[50]--;
                mp[25]--;
            } else if(mp[25]>=3) {
                mp[25] -= 3;
            } else {
                res = 0;
            }
        }
    }
    cout << (res == 1 ? "YES" : "NO") << "\n";
}

int main() {
    solve();
    return 0;
}
