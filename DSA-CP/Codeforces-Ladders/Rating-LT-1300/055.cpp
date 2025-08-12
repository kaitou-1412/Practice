// B. Present from Lena
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, num;
    cin >> n;
    for(int i=0; i<=2*n; i++) {
        for(int j=0; j<=2*n; j++) {
            if(j) cout << " ";
            if(0<=i && i<=n && 0<=j && j<=n) {
                num = i+j-n;
            } else if(0<=i && i<=n && n<j) {
                num = i-j+n;
            } else if(n<i && 0<=j && j<=n) {
                num = j-i+n;
            } else {
                num = 3*n-i-j;
            }
            if(0<=num) cout << num;
            else cout << " ";
            if(n<=j && num == 0) break;
        }
        if(i<2*n) cout << "\n";
    }
}

int main() {
    solve();
    return 0;
}
