// Coin Piles
#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long int a, b;
    cin >> a >> b;
    if(2*a>=b && (2*a-b)%3 == 0 && 2*b>=a && (2*b-a)%3 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
 
int main() {
    int t;
    cin >> t;
    while(t--) solve();
}