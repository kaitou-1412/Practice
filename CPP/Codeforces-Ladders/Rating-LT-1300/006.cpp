// A. Lights Out
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 3, press;
    int dx[5] = {0, -1, 0, 1, 0};
    int dy[5] = {0, 0, -1, 0, 1};
    vector<vector<int>> res(n, vector<int>(n, 1));
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> press;
            if(press%2 == 1) q.push({i, j});
        }
    }
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i=0; i<=4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<n) {
                res[nx][ny] = 1 - res[nx][ny];
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << res[i][j];
        }
        cout << "\n";
    }
    return 0;
}