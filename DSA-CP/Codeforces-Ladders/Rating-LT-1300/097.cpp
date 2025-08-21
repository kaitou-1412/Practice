// B. Appleman and Card Game
#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k, d, res = 0;
    string s;
    cin >> n >> k;
    cin >> s;
    vector<long long> freq(26, 0);
    for(char ch: s) freq[ch - 'A']++;
    sort(freq.begin(), freq.end());
    for(int i=25; i>=0; i--) {
        d = min(k, freq[i]);
        res += d * d;
        k -= d;
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
