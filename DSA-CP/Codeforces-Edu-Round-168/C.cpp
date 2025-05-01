#include<bits/stdc++.h>
using namespace std;

int main() {
    // Even Positions
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int res = n/2;
        for(int i=1; i<n; i+=2) {
            if(s[i] == '(') {
                res += 2;
            }
        }
        cout << res << "\n";
    }
}