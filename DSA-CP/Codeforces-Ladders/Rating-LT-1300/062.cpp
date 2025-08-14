// B. Jeff and Periods
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, res = 0;
    cin >> n;
    map<int, vector<int>> mp;
    unordered_map<int, bool> checkAP;
    unordered_map<int, int> diff;
    for(int i=0; i<n; i++) {
        cin >> a;
        mp[a].push_back(i);
        int sz = mp[a].size();
        if(sz == 1) {
            diff[a] = 0;
            checkAP[a] = true;
            res++;
        } else if(sz == 2) {
            diff[a] = mp[a][1] - mp[a][0];
        } else if(sz > 2 && checkAP[a] && mp[a][sz-1] - mp[a][sz-2] != diff[a]) {
            checkAP[a] = false;
            res--;
        }
    }
    cout << res << "\n";
    for(auto it: mp) {
        int x = it.first;
        if(checkAP[x]) {
            cout << x << " " << diff[x] << "\n";
        }  
    }
}

int main() {
    solve();
    return 0;
}
