// B. Big Segment
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, l, r, res = -1;
    cin >> n;
    int mn = INT_MAX, mx = INT_MIN;
    vector<int> vmn, vmx;
    for(int i=0; i<n; i++) {
        cin >> l >> r;
        if(l<=mn) {
            if(l<mn) vmn.clear();
            vmn.push_back(i+1);
            mn = l;            
        }
        if(mx<=r) {
            if(mx<r) vmx.clear();
            vmx.push_back(i+1);
            mx = r;
        }
    }
    for(int mini: vmn) {
        for(int maxi: vmx) {
            if(mini == maxi) {
                res = mini;
                break;
            }
        }
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
