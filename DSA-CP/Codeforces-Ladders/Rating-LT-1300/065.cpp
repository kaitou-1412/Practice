// B. Shower Line
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n = 5, res = 0;
    vector<vector<int>> g(n, vector<int>(n, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> g[i][j];
        }
    }
    for(int i1=0; i1<n; i1++) {
        for(int i2=0; i2<n; i2++) {
            if(i1==i2) continue;
            for(int i3=0; i3<n; i3++) {
                if(i3==i1 || i3==i2) continue;
                for(int i4=0; i4<n; i4++) {
                    if(i4==i1 || i4==i2 || i4==i3) continue;
                    for(int i5=0; i5<n; i5++) {
                        if(i5==i1 || i5==i2 || i5==i3 || i5==i4) continue;
                        int sum = 2*(g[i3][i4] + g[i4][i3] + g[i4][i5] + g[i5][i4]) + g[i1][i2] + g[i2][i1] + g[i2][i3] + g[i3][i2];
                        res = max(res, sum);
                    }
                }
            }
        }
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
