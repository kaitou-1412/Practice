// A. I_love_%username%
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, res = 0, p;
    cin >> n;
    cin >> p;
    int max_points = p, min_points = p;
    for(int i=1; i<n; i++) {
        cin >> p;
        if(p>max_points || p<min_points) res++;
        max_points = max(max_points, p);
        min_points = min(min_points, p);
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}