#include<bits/stdc++.h>
using namespace std;

int main() {
    // Problem Reviews
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        bool problemIsGood = true;
        int score;
        for(int i=0; i<n; i++) {
            cin >> score;
            if(score<=4) {
                problemIsGood = false;
            }
        }
        cout << (problemIsGood ? "YES" : "NO") << "\n";
    }
}