#include<bits/stdc++.h>
using namespace std;

int main() {
    // Strong Password
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        int k = n;
        string ch;
        for(int i=0; i<n; i++) {
            if(i>0 && s[i] == s[i-1]) {
                k = i;
                if(s[i] == 'z') ch = "a";
                else ch = char(s[i] + 1); 
            }
        }
        if(k != n) s = s.substr(0, k) + ch + s.substr(k, n-k);
        else {
            if(s[k-1] == 'z') ch = "a";
            else ch = char(s[k-1] + 1); 
            s += ch;
        }
        cout << s << "\n";
    }
}