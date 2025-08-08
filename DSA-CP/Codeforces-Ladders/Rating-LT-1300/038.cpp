// A. Little Elephant and Rozdil
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, res = -1, t, time = INT_MAX;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> t;
        if(t<time) {
            time = t;
            res = i+1;
        } else if(t == time) {
            res = -1;
        }
    }
    cout << (res == -1 ? "Still Rozdil" : to_string(res)) << "\n";
}

int main() {
    solve();
    return 0;
}
