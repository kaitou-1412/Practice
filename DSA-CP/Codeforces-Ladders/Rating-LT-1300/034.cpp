// A. Petr and Book
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, res = 0, week = 0;
    cin >> n;
    vector<int> pages(7);
    for(int i=0; i<7; i++) {
        cin >> pages[i];
        week += pages[i];
    }
    if(n>week) {
        n = n%week;
        if(n == 0) n = week;
    }
    for(int i=0; i<7; i++) {
        if(n<=pages[i]) {
            res = i+1;
            break;
        } else {
            n -= pages[i];
        }
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
