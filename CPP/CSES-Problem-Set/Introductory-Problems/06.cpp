// Number Spiral
#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long int x, y, res;
    cin >> x >> y;
    if(x<y) {
        res = (y-1)*(y-1);
        res += (y % 2 == 0) ? x : 2*y-x;
    } else {
        res = (x-1)*(x-1);
        res += (x % 2 == 0) ? 2*x-y : y;
    }
    cout << res << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}