// B. Dima and Friends
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, fingers, count = 0, res = 0;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> fingers;
        count += fingers;
    } 
    for(int i=1; i<=5; i++) {
        if((count + i - 1) % (n+1) != 0) {
            res++;
        }
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
