// D. Replace with Occurrences
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, x = 1;
    cin >> n;
    vector<int> id(n+1, 0), a(n+1, 0), b(n+1, 0);
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    bool f = false;
    for(int i=1; i<=n; i++) {
        if(b[a[i]]%a[i]!=0) {
            f = true;
            break;
        }
    }
    if(f) cout << -1 << "\n";
    else {
        for(int i=1; i<=n; i++) {
            if(b[a[i]]%a[i] == 0) {
                id[a[i]] = x;
                x++;
            }
            cout << id[a[i]] << " ";
            b[a[i]]--;
        }
        cout << "\n";        
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}