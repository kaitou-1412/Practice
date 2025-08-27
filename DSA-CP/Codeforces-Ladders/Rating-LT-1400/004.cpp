// A. Blackjack
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> ways(12, 0);
    for(int i=1; i<=13; i++) {
        if(i == 1) {
            ways[1] += 4;
            ways[11] += 4;
        } else if(2<=i && i<10) {
            ways[i] += 4;
        } else {
            ways[10] += 4;
        }
    }
    ways[10]--;
    n -= 10;
    if(n<1 || n>11) cout << 0 << "\n";
    else cout << ways[n] << "\n";
}

int main() {
    solve();
    return 0;
}
