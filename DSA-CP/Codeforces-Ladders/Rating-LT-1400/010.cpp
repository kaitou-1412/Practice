// B. Drinks
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    double sum = 0, p;
    for(int i=0; i<n; i++) {
        cin >> p;
        sum += p;
    }
    double res = sum/n;
    cout.precision(12);
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
