// A. Lunch Rush
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, f, t, max_joy;
    cin >> n >> k;
    cin >> f >> t;
    if(t>k) f -= t-k;
    max_joy = f;
    if(n>1) {
        for(int i = 1; i<n; i++) {
            cin >> f >> t;
            if(t>k)
                f -= t-k;
            if(max_joy<f)
                max_joy = f;
        }
    }
    cout << max_joy << "\n";
}

int main() {
    solve();
    return 0;
}
