// Missing Number
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, num;
    cin >> n;
    int res = n;
    for(int i=1; i<n; i++) {
        cin >> num;
        res ^= i^num;
    }
    cout << res << "\n";
}