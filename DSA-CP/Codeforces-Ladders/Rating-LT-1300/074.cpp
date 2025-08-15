// A. Yaroslav and Permutations
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, a;
    cin >> n;
    string res = "YES";
    unordered_map<int, int> freq;
    for(int i=0; i<n; i++) {
        cin >> a;
        freq[a]++;
        if(res != "NO" && freq[a] > (n+1)/2) {
            res = "NO";
        }
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
