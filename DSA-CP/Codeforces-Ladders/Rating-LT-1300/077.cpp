// B. Increase and Decrease
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, a;
    cin >> n;
    long long int sum = 0;
    for(int i=0; i<n; i++) {
        cin >> a;
        sum += a;
    }
    int res = n-1;
    if(sum%n == 0) res = n;
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
