// A. Petya and Strings
#include<bits/stdc++.h>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    for (char &c : a) c = tolower(c);
    for (char &c : b) c = tolower(c);
    if (a < b) {
        cout << "-1\n";
    } else if (a == b) {
        cout << "0\n";
    } else {
        cout << "1\n";
    }
}

int main() {
    solve();
    return 0;
}
