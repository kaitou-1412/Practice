// Creating Strings
#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> arr;
    do {
        arr.push_back(s);
    } while(next_permutation(s.begin(), s.end()));
    cout << arr.size() << "\n";
    for(auto it: arr) {
        cout << it << "\n";
    }
}
 
int main() {
    // int t;
    // cin >> t;
    // while(t--) solve();
    solve();
}