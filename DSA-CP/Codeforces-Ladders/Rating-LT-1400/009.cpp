// A. Candy Bags
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a = 1, b = n*n;
    for(int row=1; row<=n; row++) {
        for(int i=1; i<=n/2; i++) {
            cout << a << " " << b << " ";
            a++;
            b--;
        }
        cout << "\n";
    }
}

int main() {
    solve();
    return 0;
}
