// Traffic Lights
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int x, n;
    cin >> x >> n;
    int p;
    set<int> numSet;
    numSet.insert(0);
    numSet.insert(x);
    multiset<int> lengthMultiSet;
    lengthMultiSet.insert(x);
    for(int i=0; i<n; i++) {
        cin >> p;
        numSet.insert(p);
        auto it = numSet.find(p);
        int prevNum = *prev(it), nextNum = *next(it);
        lengthMultiSet.erase(lengthMultiSet.find(nextNum - prevNum));
        lengthMultiSet.insert(p - prevNum);
        lengthMultiSet.insert(nextNum - p);
        cout << *lengthMultiSet.rbegin() << " ";
    }
}
 
int main() {
    // int t;
    // cin >> t;
    // while(t--) solve();
    ios_base::sync_with_stdio(false);
    solve();
}