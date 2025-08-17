// B. Easy Number Challenge
#include<bits/stdc++.h>
using namespace std;


void solve() {
    int mod = 1000000;
    int a, b, c;
    vector<int> d(mod+1, 0);
    for(int i=1; i<=mod; i++) for(int j=i; j<=mod; j+=i) ++d[j];
    cin >> a >> b >> c;
    long long int res = 0;
    for(int i=1; i<=a; i++) for(int j=1; j<=b; j++) for(int k=1; k<=c; k++) res += d[i*j*k];
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
