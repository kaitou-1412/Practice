// A. Stones on the Table
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, res = 0;
    cin >> n;
    string s;
    cin >> s;
    char prev = 'x';
    int count = 0;
    for(char ch: s) {
        if(prev != 'x' && ch != prev) {
            if(count>1) res += count-1;
            count = 0;
        }
        count++;
        prev = ch;
    }
    if(count>1) res += count-1;
    cout << res << "\n";
    return 0;
}