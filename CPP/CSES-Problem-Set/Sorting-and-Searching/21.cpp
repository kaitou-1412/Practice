// Apartments
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    long long int k;
    cin >> n >> m >> k;
    long long int a[n], b[m];
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    int apartmentIndex = 0, res = 0;;
    for(auto desiredSize: a) {
        while(apartmentIndex < m && b[apartmentIndex] < desiredSize - k) {
            apartmentIndex++;
        }
        if(apartmentIndex >= m) {
            break;
        }
        if(b[apartmentIndex] <= desiredSize + k) {
            apartmentIndex++;
            res++;
        }
    }
    cout << res << "\n";
}
 
int main() {
    // int t;
    // cin >> t;
    // while(t--) solve();
    ios_base::sync_with_stdio(false);
    solve();
}