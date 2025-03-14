// A. Nearly Lucky Number
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

int main() {
    long long n;
    cin >> n;
    cout << (is_nearly_lucky(n) ? "YES" : "NO") << "\n";
    return 0;
}