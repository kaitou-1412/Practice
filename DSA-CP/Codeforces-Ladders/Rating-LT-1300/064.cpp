// B. Sail
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int t, sx, sy, ex, ey, res = -1;
    cin >> t >> sx >> sy >> ex >> ey;
    string s;
    cin >> s;
    for(int i=0; i<t; i++) {
        if(s[i] == 'N') {
            if(sy < ey) sy++;
        } else if(s[i] == 'S') {
            if(sy > ey) sy--;
        } else if(s[i] == 'W') {
            if(sx > ex) sx--;
        } else if(s[i] == 'E') {
            if(sx < ex) sx++;
        }
        if(sx == ex && sy == ey) {
            res = i + 1;
            break;
        }
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
