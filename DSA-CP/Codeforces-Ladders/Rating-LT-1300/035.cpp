// A. Parallelepiped
#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int s = sqrt(a*b*c);
    cout << 4*((s/a) + (s/b) + (s/c)) << "\n";
}

int main() {
    solve();
    return 0;
}
