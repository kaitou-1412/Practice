#include<bits/stdc++.h>
using namespace std;

int sumOfDigits(int n) {
    int res = 0;
    while(n) {
        res += n%10;
        n /= 10;
    }
    return res;
}

int main() {
    // --------
    int t;
    cin >> t;
    unordered_map<int, long long> dp;
    int maxi = 1;
    while(t--) {
        int n;
        cin >> n;
        long long res = 0;
        for(int i=min(maxi, n); i<=n; i++) {
            if(dp[i]) res = dp[i];
            else {
                res += sumOfDigits(i);
                dp[i] = res;
            }
        }
        maxi = max(maxi, n);
        cout << res << "\n";
    }
}