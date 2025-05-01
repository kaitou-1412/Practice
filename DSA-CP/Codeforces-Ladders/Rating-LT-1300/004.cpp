// B. Borze
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    string res = "";
    for(int i=0; i<n; i++) {
        if(s[i] == '.') res += '0';
        else if(i+1<n && s[i+1] == '.') {
            res += '1';
            i++;
        } else {
            res += '2';
            i++;
        }
    }
    cout << res << "\n";
}