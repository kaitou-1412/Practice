// B. Sereja and Suffixes
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, l;
    cin >> n >> m;
    vector<int> a(n), res(n+1);
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    for(int i=0; i<n; i++) {
        res[i+1] = mp.size();
        mp[a[i]]--;
        if(mp[a[i]] == 0) mp.erase(a[i]); 
    }
    for(int i=0; i<m; i++) {
        cin >> l;
        cout << res[l] << "\n";
    }
}

int main() {
    solve();
    return 0;
}
