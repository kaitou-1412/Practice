#include<bits/stdc++.h>
using namespace std;

bool noMatchingBitValues(int i, int j, vector<long long> &a) {
    for(int digit=0; digit<32; digit++) {
        int count = 0;
        for(int index = i; index<=j; index++) {
            if(a[index] & (1ll << digit)){
                count++;
            }
            if(count > 1) return false;
        }
    }
    return true;
}

int main() {
    // Vlad and Division
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        const int64_t inf = (int64_t(1) << 31) - 1;
        int l = 0, r = n - 1;
        int ans = n;
        while (l < r) {
            if (a[l] + a[r] == inf) {
                ans -= 1;
                l += 1;
                r -= 1;
            } else {
                if (a[l] + a[r] > inf) {
                    r -= 1;
                } else {
                    l += 1;
                }
            }
        }
        cout << ans << '\n';
    }
}