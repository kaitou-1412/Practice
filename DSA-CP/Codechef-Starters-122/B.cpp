#include<bits/stdc++.h>
using namespace std;

int main() {
    // Man of the Match
    int t;
    cin >> t;
    while(t--) {
        int n = 22;
        int a, b, maxPlayerScore = INT_MIN, index;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            int currPlayerScore = a + 20*b;
            if(maxPlayerScore < currPlayerScore) {
                maxPlayerScore = currPlayerScore;
                index = i+1;
            }
        }
        cout << index << '\n';
    }
}