// Restaurant Customers
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a, b;
    multiset<int> in, out;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        in.insert(a);
        out.insert(b);
    }
    int people = 0, res = 0;
    while (!in.empty()) {
        people++;
        while(!out.empty() && *out.begin() <= *in.begin()) {
            people--;
            out.erase(out.begin());
        }
        res = max(res, people);
        in.erase(in.begin());
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