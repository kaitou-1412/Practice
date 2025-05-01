#include<bits/stdc++.h>
using namespace std;

int main() {
    // Vlad and the Best of Five
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int count = 0;
        for(char c: s) if(c == 'A') count++;
        char ch = count > (5-count) ? 'A' : 'B';
        cout << ch << "\n";
    }
}