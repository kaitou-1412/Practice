// Apple Division
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long int> p(n);
    long long int total = 0, diff = INT64_MAX;
    for(int i=0; i<n; i++) {
        cin >> p[i];
        total += p[i];
    }
    for(long long int i=0; i<(1<<n); i++) {
        long long int sum = 0;
        for(int j=0; j<n; j++) {
            if(i&(1<<j)) {
                sum += p[j];
            }
        }
        long long int currDiff = abs((total - sum) - sum);
        diff = min(diff, currDiff);
    }
    cout << diff << "\n";
}
 
int main() {
    // int t;
    // cin >> t;
    // while(t--) solve();
    solve();
}