// A. Dubstep
#include<bits/stdc++.h>
using namespace std;

void solve() {
    string word;
    cin >> word;
    vector<string> words_list;
    size_t pos = 0, found;
    while ((found = word.find("WUB", pos)) != string::npos) {
        if (found > pos) {
            words_list.push_back(word.substr(pos, found - pos));
        }
        pos = found + 3;
    }
    if (pos < word.size()) {
        words_list.push_back(word.substr(pos));
    }
    for (size_t i = 0; i < words_list.size(); ++i) {
        if (i > 0) cout << " ";
        cout << words_list[i];
    }
    cout << "\n";
}

int main() {
    solve();
    return 0;
}
