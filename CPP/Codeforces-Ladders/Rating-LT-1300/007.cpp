// A. Word
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size(), lowercase = 0;
    for(char ch: s) if('a' <= ch && ch <= 'z') lowercase++;
    int uppercase = n - lowercase;
    if(lowercase<uppercase) {
        for(int i=0; i<n; i++) {
            if('a' <= s[i] && s[i] <= 'z') {
                s[i] -= 32; 
            }
        }
    } else {
        for(int i=0; i<n; i++) {
            if('A' <= s[i] && s[i] <= 'Z') {
                s[i] += 32; 
            }
        }
    }
    cout << s << "\n";
    return 0;
}