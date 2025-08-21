// A. Sereja and Bottles
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, open = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i] >> b[i];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i!=j && a[i]==b[j]) {
                open++;
                break;
            }
        }
    }
    cout << n-open << "\n";
}

int main() {
    solve();
    return 0;
}
