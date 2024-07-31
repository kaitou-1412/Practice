#include<bits/stdc++.h>
using namespace std;

bool noMatchingBitValues(int i, int j, vector<long long> &a) {
    for(int digit=0; digit<32; digit++) {
        int count = 0;
        for(int index = i; index<=j; index++) {
            if(a[index] & (1ll << digit)){
                count++;
            }
            if(count > 1) return false;
        }
    }
    return true;
}

int main() {
    // --------
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            cin >> p[i];
            --p[i];
            g[p[i]].push_back(i);
        }
        string s;
        cin >> s;
        vector<int> val(n);
        for (int i = 0; i < n; i++) {
            val[i] = (s[i] == 'P' ? 0 : (s[i] == 'S' ? 1 : 2));
        }
        const int inf = int(1e9);
        vector<vector<int>> dp(n, vector<int>(3, 0));
        auto Dfs = [&](auto&& self, int v) -> void {
            for (int u : g[v]) {
                self(self, u);
                for (int x = 0; x < 3; x++) {
                    int best = inf;
                    for (int y = 0; y < 3; y++) {
                        int add = 0;
                        if (x + y == 1 || (x == 2 && y < 2)) {
                            add = 1;
                        }
                        best = min(best, dp[u][y] + add);
                    }
                    dp[v][x] += best;
                }
            }
            if (val[v] < 2) {
                dp[v][1 - val[v]] = dp[v][2] = inf;
            }
        };
        Dfs(Dfs, 0);
        cout << min({dp[0][0], dp[0][1], dp[0][2]}) << '\n';
    }
}