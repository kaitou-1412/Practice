// A. Jzzhu and Children
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, a, res = 0;
    cin >> n >> m;
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++) {
        cin >> a;
        q.push({i+1, a});
    } 
    while(!q.empty()) {
        int pos = q.front().first, a = q.front().second;
        if(a<=m) {
            q.pop();
            if(q.empty()) res = pos;
        } else {
            a -= m;
            q.pop();
            q.push({pos, a});
        }
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
