// Collecting Numbers
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int x[n];
    map<int, int> pos;
    for(int i=0; i<n; i++) {
        cin >> x[i];
        pos[x[i]] = i;
    }
    int res = 1;
    for(int num=1; num<n; num++) {
        if(pos[num+1] < pos[num]) {
            res++;
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