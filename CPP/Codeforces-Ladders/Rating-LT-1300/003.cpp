// B. Queue at the School
#include<bits/stdc++.h>
using namespace std;

void transform(int n, string &s) {
    for(int i=1; i<n; i++) {
        if(s[i-1] == 'B' && s[i] == 'G') {
            s[i-1] = 'G';
            s[i] = 'B';
            i++;
        }
    }
}

int main() {
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    while(t--) transform(n, s);
    cout << s << "\n";
    return 0;
}