// A. Insomnia cure
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    vector<int> v(d+1, 0);
    int res = 0;
    for(int i=l; i<=d; i+=l) if(!v[i]) v[i] = 1;
    for(int i=m; i<=d; i+=m) if(!v[i]) v[i] = 1;
    for(int i=n; i<=d; i+=n) if(!v[i]) v[i] = 1;
    for(int i=k; i<=d; i+=k) if(!v[i]) v[i] = 1;
    for(int i=1; i<=d; i++) if(v[i]) res++;
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}