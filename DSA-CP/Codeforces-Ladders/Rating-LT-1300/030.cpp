// B. Effective Approach
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, b;
    long long int vasya = 0, petya = 0;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> pos;
     for(int i=0; i<n; i++) {
        cin >> a[i];
        pos[a[i]] = i+1;
    }
    cin >> m; 
    for(int i=0; i<m; i++) {
        cin >> b;
        vasya += pos[b];
        petya += n-pos[b]+1;
    }
    cout << vasya << " " << petya << "\n";
}

int main() {
    solve();
    return 0;
}
