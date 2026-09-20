// Terraces
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> directions = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

void bfs(int x, int y, int &res, vector<vector<bool>> &vis, vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    bool can_drain = false;
    int count = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;
    while(!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();
        count++;
        for(auto dir: directions) {
            int xn = r + dir[0], yn = c + dir[1];
            if(0>xn || xn>=n || 0>yn || yn>=m || grid[r][c]<grid[xn][yn]) continue;
            if(grid[r][c] > grid[xn][yn]) {
                can_drain = true;
            } else if(grid[r][c] == grid[xn][yn]) {
                if(!vis[xn][yn]) {
                    q.push({xn, yn});
                    vis[xn][yn] = true;
                }
            }
        }
    }
    if(!can_drain) {
        res += count;
    }
}

void solve() {
    int n, m, res = 0;
    cin >> m >> n;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!vis[i][j]) {
                bfs(i, j, res, vis, grid);
            }
        }
    }
    cout << res << "\n";
}

int main() {
    solve();
}
