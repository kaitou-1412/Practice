// Repetitions
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int res = 0, count = 1;
    for(int i=1; i<s.size(); i++) {
        if(s[i] == s[i-1]) {
            count++;
        } else {
            res = max(res, count);
            count = 1;
        }
    }
    res = max(res, count);
    cout << res << "\n";
}