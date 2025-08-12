// A. DZY Loves Chessboard
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    char board[n][m];
    char b = 'B', w = 'W';
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            cin >> board[i][j];
        }
    }
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(board[i][j] == '.') {
                if((i+j) & 1) {
                    board[i][j] = b;
                } else {
                    board[i][j] = w;
                }
            }
        }
    }
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

int main() {
    solve();
    return 0;
}
