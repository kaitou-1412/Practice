// A. Amusing Joke
#include<bits/stdc++.h>
using namespace std;

void solve() {
    string guest, host, s, pile;
    cin >> guest >> host >> pile;
    s = guest + host;
    sort(s.begin(), s.end());
    sort(pile.begin(), pile.end());
    cout << (s == pile ? "YES" : "NO") << "\n";
}

int main() {
    solve();
    return 0;
}
