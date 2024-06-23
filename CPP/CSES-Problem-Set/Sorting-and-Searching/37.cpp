// Nested Ranges Check
#include<bits/stdc++.h>
using namespace std;

// Comparator for the multiset
struct comparator {
    bool operator()(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) const {
        if (a.first.first == b.first.first) {
            return a.first.second > b.first.second; // Descending order for the second int
        }
        return a.first.first < b.first.first; // Ascending order for the first int
    }
};

void solve() {
    int n;
    cin >> n;
    int a, b;
    multiset<pair<pair<int, int>, int>, comparator> ms;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        ms.insert({{a, b}, i});
    }
    int contains[n], contained[n];
    for(int i=0; i<n; i++) contains[i] = 0;
    for(int i=0; i<n; i++) contained[i] = 0;
    int maxRight = 0, minRight = INT32_MAX;
    for(auto it: ms) {
        if(it.first.second <= maxRight) {
            contained[it.second] = 1;
        } 
        maxRight = max(maxRight, it.first.second);
    }
    auto it = ms.rbegin();
    while(it != ms.rend()) {
        if((*it).first.second >= minRight) {
            contains[(*it).second] = 1;
        }
        minRight = min(minRight, (*it).first.second);
        it++;
    }
    for(int i=0; i<n; i++) {
        cout << contains[i] << " ";
    }
    cout << "\n";
    for(int i=0; i<n; i++) {
        cout << contained[i] << " ";
    }
    cout << "\n";
}
 
int main() {
    // int t;
    // cin >> t;
    // while(t--) solve();
    ios_base::sync_with_stdio(false);
    solve();
}