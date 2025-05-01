// Playlist
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int res = 0;
    set<int> st;
    int i = 0, j = 0;
    while(i<n && j<n) {
        while(j<n && !st.count(a[j])) {
            st.insert(a[j]);
            res = max(res, j-i+1);
            j++;
        }
        while(j<n && st.count(a[j])) {
            st.erase(a[i]);
            i++;
        }
    }
    cout << res << "\n";
}
 
int main() {
    // int t;
    // cin >> t;
    // while(t--) solve();
    ios_base::sync_with_stdio(false);
    solve();
}