// A. String Task
#include<bits/stdc++.h>
using namespace std;

void solve() {
    string word;
    cin >> word;
    // Convert to lowercase
    for (char &c : word) c = tolower(c);

    set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};
    string res;
    for (char c : word) {
        if (vowels.count(c) == 0) {
            res += '.';
            res += c;
        }
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
