// C. Maximum Even Sum
#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;
    if (b%2 == 1 && a%2 == 1) cout << a*b + 1 << "\n";
    else if (b%2 == 1 && a%2 == 0) cout << "-1" << "\n";
    else {
        int p = 0;
        long long tempb = b;
        while(tempb%2 == 0) {
            tempb >>= 1;
            p++;
        }
        if(a%2 == 1 && p == 1) cout << "-1" << "\n";
        else {
            int k = (a%2 == 1) ? 2 : 1;
            long long s1 = a*k + b/k;
            long long s2 = a*(b/2) + 2;
            cout << max(s1, s2) << "\n";
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}