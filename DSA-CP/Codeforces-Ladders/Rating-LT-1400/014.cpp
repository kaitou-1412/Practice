// A. Stones on the Table
#include<bits/stdc++.h>
using namespace std;

bool is_lucky(long long n) {
    if(n == 0) return false;
    while(n>0) {
        if(n%10 != 4 && n%10 != 7) {
            return false;
        }
        n = n/10;
    }
    return true;
}
 
bool is_nearly_lucky(long long n) {
    long long lucky_digits = 0;
    while(n>0) {
        if(is_lucky(n%10)) {
            lucky_digits++;
        }
        n = n/10;
    }
    return is_lucky(lucky_digits);
}

void solve() {
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
}

int main() {
    solve();
    return 0;
}
