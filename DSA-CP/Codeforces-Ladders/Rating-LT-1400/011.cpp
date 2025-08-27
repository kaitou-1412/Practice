// A. Vasily the Bear and Triangle
#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long x, y, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    cin >> x >> y;
    long long s = abs(x) + abs(y);
    if(x>0 && y>0) {
        y1 = s;
        x2 = s;
    } else if(x<0 && y>0) {
        y2 = s;
        x1 -= s;
    } else if(x<0 && y<0) {
        y2 -= s;
        x1 -= s;
    } else {
        y1 -= s;
        x2 = s;
    }
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
}

int main() {
    solve();
    return 0;
}
