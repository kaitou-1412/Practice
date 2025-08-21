// C. Building Permutation
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long int res = 0;
    cin>> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++) res += abs(i+1-a[i]);
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
