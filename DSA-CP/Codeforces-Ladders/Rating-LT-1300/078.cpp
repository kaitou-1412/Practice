// A. Two Bags of Potatoes
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int y, k, n;
    cin >> y >> k >> n;
    bool res = false;
    for(int x=k-y%k; x+y<=n; x+=k) {
        if((x+y)%k == 0) {
            res = true;
            cout << x << " ";
        }
    }
    if(!res) cout << "-1";
    cout << "\n";
}

int main() {
    solve();
    return 0;
}
