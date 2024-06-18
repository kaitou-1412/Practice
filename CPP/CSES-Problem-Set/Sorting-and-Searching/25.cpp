// Movie Festival
#include<bits/stdc++.h>
using namespace std;

// Comparator for the multiset
struct comparator {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.second == b.second) {
            return a.first > b.first; // Descending order for the first int
        }
        return a.second < b.second; // Ascending order for the second int
    }
};

void solve() {
    int n;
    cin >> n;
    int a, b;
    multiset<pair<int, int>, comparator> ms;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        ms.insert({a, b});
    }
    int res = 0, prev = 0;
    for(auto p: ms) {
        if(prev > p.first) continue;
        res++;
        prev = p.second;
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