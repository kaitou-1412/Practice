#include<bits/stdc++.h>
using namespace std;

bool is_non_degenerate_triangle(long long a, long long b, long long c) {
    return (a+b>c) && (b+c>a) && (c+a>b);
}

int main() {
    // C. XOR and Triangle
    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        int res = -1;
        for(int i=0; i<=30; i++) {
            for(int j=0; j<=30; j++) {
                int y = (1 << i) | (1 << j);
                if(y<x && is_non_degenerate_triangle(x, y, x^y)) {
                    res = y;
                    // break;
                }
            }
            // if(res != -1) break;
        }
        cout << res << "\n";
    }
}