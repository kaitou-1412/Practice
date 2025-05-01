#include<bits/stdc++.h>
using namespace std;

int main() {
    // Arya In Grid
    int t;
    cin >> t;
    while(t--) {
        int n, m, x, y, l;
        cin >> n >> m >> x >> y >> l;
        int rows = (n-1)/l, cols = (m-1)/l;
        if((x-1)%l <= (n-1)%l) rows++;
        if((y-1)%l <= (m-1)%l) cols++;
        long long res = (long long)rows*cols;
        cout << res << '\n';
    }
}