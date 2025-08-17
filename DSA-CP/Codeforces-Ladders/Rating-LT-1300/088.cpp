// A. IQ Test
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n = 4;
    string s;
    int a[4][4] = {0};
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<n; j++) {
            a[i][j] = (s[j] == '#') ? 1 : 0;
        }  
    }
    bool res1 = false, res2 = false;
    for(int i=1; i<n; i++) {
        for(int j=1; j<n; j++) {
            if(a[i-1][j-1] + a[i-1][j] + a[i][j-1] + a[i][j] >= 3) res1 = true;
            if(a[i-1][j-1] + a[i-1][j] + a[i][j-1] + a[i][j] <= 1) res2 = true;
        }    
    }
    cout << ((res1 || res2) ? "YES" : "NO") << "\n";
}

int main() {
    solve();
    return 0;
}
