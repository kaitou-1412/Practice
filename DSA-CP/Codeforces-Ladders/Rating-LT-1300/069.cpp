// A. Kitahara Haruki's Gift
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, w, w1 = 0, w2 = 0;
    string res = "NO";
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> w;
        if(w == 100) {
            w1++;
        } else {
            w2++;
        }
    }
    if((w1%2 == 0 && w2%2 == 0) || (w1%2 == 0 && w2%2 == 1 && w1>=2)) res = "YES";
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
