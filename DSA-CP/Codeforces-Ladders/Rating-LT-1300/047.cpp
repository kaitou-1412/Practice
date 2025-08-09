// A. System of Equations
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, res = 0;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0; i<=32; i++) {
        for(int j=0; j<=32; j++) {
            if((i*i + j) == n && (i + j*j) == m) {
                res++;
            }
        }
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
