// Knight in a War Grid
#include<bits/stdc++.h>
using namespace std;

void solve(int case_number) {
    int r, c, m, n, w, x, y, even = 0, odd = 0;
    cin >> r >> c >> m >> n;
    vector<vector<int>> directions = {
        {-m, -n},
        {-m, n},
        {m, -n},
        {m, n},
        {-n, -m},
        {-n, m},
        {n, -m},
        {n, m}
    };
    vector<vector<int>> grid(r, vector<int>(c, 0));
    vector<vector<int>> vis(r, vector<int>(c, 0));
    cin >> w;
    for(int i=0; i<w; i++) {
        cin >> x >> y;
        grid[x][y] = -1;
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = 1;
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        set<pair<int, int>> unique_neighbors;
        for(auto direction: directions) {
            int xn = x + direction[0], yn = y + direction[1];
            if(0>xn || xn>=r || 0>yn || yn>=c || grid[xn][yn] == -1) continue;
            unique_neighbors.insert({xn, yn});
            if(vis[xn][yn] != 1) {
                q.push({xn, yn});
                vis[xn][yn] = 1;
            }
        }
        grid[x][y] = unique_neighbors.size();
    }
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(grid[i][j] == -1) continue;
            if(vis[i][j] == 1) {
                if(grid[i][j]%2 == 0) even++;
                else odd++;
            }
        }
    }
    cout << "Case " << case_number << ": " << even << " " << odd << "\n";
}

int main() {
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}
