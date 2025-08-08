// A. Jeff and Digits
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, card, fives = 0, zeroes = 0;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> card;
        if(card == 5) fives++;
        else if(card == 0) zeroes++;
    }
    if(zeroes>=1 && fives>=9) {
        int printFives = fives/9;
        while(printFives--) cout << "555555555";
        while(zeroes--) cout << "0";
    } else if(zeroes>=1) {
        cout << "0";
    } else {
        cout << "-1";
    }
    cout << "\n";
}

int main() {
    solve();
    return 0;
}
