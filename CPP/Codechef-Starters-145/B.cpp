#include<bits/stdc++.h>
using namespace std;

int main() {
    // Make My Array Equal
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long a[n];
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] != 0) {
                mp[a[i]]++;
            }
        }
        cout << (mp.size() <= 1 ? "YES" : "NO") << "\n";
    }
}