// A. Chat room
#include<bits/stdc++.h>
using namespace std;

void solve() {
    string check = "hello";
    string word;
    cin >> word;
    int a = 0;
    for(int i = 0; i< word.length(); i++) {
        if(word[i] == check[a]) {
            a++;
        }
    }
    if(a==5) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    solve();
    return 0;
}
