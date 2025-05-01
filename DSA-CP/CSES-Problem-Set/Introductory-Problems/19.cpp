// Grid Paths
#include<bits/stdc++.h>
using namespace std;

int n = 7;
bool visited[7][7];
int paths = 0, steps = 0;
int reserved[49];

void grid(int r, int c) {
    if(
        visited[r][c]
        || ((0<c && c<n-1 && !visited[r][c+1] && !visited[r][c-1]) && ((r==0 && visited[r+1][c]) || (r==n-1 && visited[r-1][c]))) 
        || ((0<r && r<n-1 && !visited[r+1][c] && !visited[r-1][c]) && ((c==0 && visited[r][c+1]) || (c==n-1 && visited[r][c-1])))
        || (0<r && r<n-1 && 0<c && c<n-1 && !visited[r+1][c] && !visited[r-1][c] && visited[r][c+1] && visited[r][c-1])
        || (0<r && r<n-1 && 0<c && c<n-1 && visited[r+1][c] && visited[r-1][c] && !visited[r][c+1] && !visited[r][c-1])
    ) {
        return;
    }
    if(r == n-1 && c == 0) {
        if(steps == (n*n - 1)) paths++;
        return;
    }
    visited[r][c] = true;
    int dir = reserved[steps];
    if((dir == 0 || dir == 1) && r > 0 && !visited[r-1][c]) {
        steps++;
        grid(r-1, c);
        steps--;
        if(dir != 0) {
            visited[r][c] = false;
            return;
        }
    }
    if((dir == 0 || dir == 2) && c > 0 && !visited[r][c-1]) {
        steps++;
        grid(r, c-1);
        steps--;
        if(dir != 0) {
            visited[r][c] = false;
            return;
        }
    }
    if((dir == 0 || dir == 3) && c+1 < n && !visited[r][c+1]) {
        steps++;
        grid(r, c+1);
        steps--;
        if(dir != 0) {
            visited[r][c] = false;
            return;
        }
    }
    if((dir == 0 || dir == 4) && r+1 < n && !visited[r+1][c]) {
        steps++;
        grid(r+1, c);
        steps--;
        if(dir != 0) {
            visited[r][c] = false;
            return;
        }
    }
    visited[r][c] = false;
}

void solve() {
    string s;
    cin >> s;
    for(int i=0; i<n*n-1; i++) {
        if(s[i] == 'U') {
            reserved[i] = 1;
        } else if(s[i] == 'L') {
            reserved[i] = 2;
        } else if(s[i] == 'R') {
            reserved[i] = 3;
        } else if(s[i] == 'D') {
            reserved[i] = 4;
        } else {
            reserved[i] = 0;
        }
    }
    grid(0, 0);
    cout << paths << "\n";
}
 
int main() {
    // int t;
    // cin >> t;
    // while(t--) solve();
    ios_base::sync_with_stdio(false);
    solve();
}