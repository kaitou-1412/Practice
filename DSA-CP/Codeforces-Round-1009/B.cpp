#include<bits/stdc++.h>
using namespace std;

int main() {
    // B. The Third Side
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        int res = a[0];
        if(n > 1) {
            for(int i=1; i<n; i++) {
                res += a[i] - 1;
            }
        }
        cout << res << '\n';
    }
}