// A. Bicycle Chain
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, ratio = 0, res = 0;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for(int j=0; j<m; j++) cin >> b[j];
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(b[j] % a[i] == 0) {
                if(ratio <= b[j]/a[i]) {
                    ratio = b[j]/a[i];
                    mp[ratio]++;
                    res = mp[ratio];
                }
            }
        }
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
