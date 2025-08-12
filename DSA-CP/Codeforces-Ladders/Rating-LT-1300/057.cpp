// A. Puzzles
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int a[m];
    for(int i = 0; i<m; i++)
        cin >> a[i];
    vector <int> v(a, a+m);
    sort(v.begin(), v.end());
    int min_ele = v[n-1] - v[0];
    int diff;
    for(int i = 1; i<=m-n; i++) {
        diff = v[i+n-1]-v[i];
        if(min_ele > diff) {
            min_ele = diff;
        }
    }
    cout << min_ele << "\n";
}

int main() {
    solve();
    return 0;
}
