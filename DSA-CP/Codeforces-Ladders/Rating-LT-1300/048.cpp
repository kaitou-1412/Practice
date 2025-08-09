// A. Business trip
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int k, sum = 0, res = 0;
    cin >> k;
    vector<int> a(12);
    for(int i=0; i<12; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for(int i=11; i>=0; i--) {
        res++;
        sum += a[i];
        if(sum >= k) break;
    }
    if(res == 12 && sum < k) res = -1;
    if(k == 0) res = 0;
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
