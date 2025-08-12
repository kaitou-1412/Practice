// A. Dragons
#include<bits/stdc++.h>
using namespace std;

struct Monster {
    int x, y;
};
 
bool compareTwoMonsters(Monster a, Monster b) {
    return (a.x < b.x);
}

void solve() {
    int s, n, flag = 0;
    cin >> s >> n;
    Monster m[n];
    for(int i = 0; i<n; i++) {
        cin >> m[i].x >> m[i].y;
    }
    sort(m, m+n, compareTwoMonsters);
    for(int i = 0; i<n; i++) {
        if(s > m[i].x) {
            s += m[i].y;
        } else {
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    solve();
    return 0;
}
