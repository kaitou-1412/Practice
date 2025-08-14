// B. Little Girl and Game
#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size(), res = -1;
    unordered_map<char, int> count;
    for(int i=0; i<n; i++) count[s[i]]++;
    for(char ch='a'; ch<='z'; ch++) if(count[ch]%2) res++;
    cout << ((res<=0 || res%2==0) ? "First" : "Second") << "\n";
}

int main() {
    solve();
    return 0;
}
