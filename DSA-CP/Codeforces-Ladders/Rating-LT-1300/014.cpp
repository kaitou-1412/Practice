// A. Arrival of the General
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, res = 0;
    cin >> n;
    int a[n];
    cin >> a[0];
    int max_index = 0;
    for(int i=1; i<n; i++) {
        cin >> a[i];
        if(a[i] > a[max_index]) max_index = i;
    }
    res += max_index;
    int min_index = n-1;
    for(int i = n-2; i>=0; i--) if(a[i] < a[min_index]) min_index = i;
    res += n-1-min_index;
    if(min_index < max_index) res--;
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}