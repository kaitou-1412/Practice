// B. Polo the Penguin and Matrix
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, d, sum = 0;
    cin >> n >> m >> d;
    vector<int> a(n * m);
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> a[m*i + j];
    sort(a.begin(), a.end());
    for(int i=0; i<n*m; i++) sum += abs(a[i] - a[n*m/2]);
    if(sum%d == 0) cout << sum/d << "\n";
    else cout << "-1\n";
}

int main() {
    solve();
    return 0;
}
