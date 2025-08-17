// A. Pythagorean Theorem II
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, res = 0;
    cin >> n;
    for(int a=1; a<=n; a++) {
        for(int b=a; b<=n; b++) {
            int c = sqrt(a*a + b*b);
            if(c<=n && c*c == a*a + b*b) {
                res++;
            }
        }
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
