// A. Petya and Strings
#include<bits/stdc++.h>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    transform(
        a.begin(),
        a.end(),
        a.begin(),
        [](char c){ return tolower(c); }
    );
    transform(
        b.begin(),
        b.end(),
        b.begin(),
        [](char c){ return tolower(c); }
    );
    if (a < b) {
        cout << "-1";
    } else if (a == b) {
        cout << "0";
    } else if (a > b) {
        cout << "1";
    }
    cout << "\n";
}

int main() {
    solve();
    return 0;
}
