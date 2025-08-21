// A. Flipping Game
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a, ones = 0, extraSum = 0, res = -1;
    for(int i=0; i<n; i++) {
        cin >> a;
        ones += a;
        extraSum += 1-2*a;
        res = max(res, extraSum);
        extraSum = max(extraSum, 0);
    }
    ones += res;
    cout << ones << "\n";
}

int main() {
    solve();
    return 0;
}
