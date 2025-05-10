#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, fee = 2;
    cin >> n;
    vector<int> prices(n);
    for(int i=0; i<n; i++) cin >> prices[i];
    vector<vector<int>> dp(n+1, vector<int>(2, 0));
    for(int start=n-1; start>=0; start--) {
        for(int action=0; action<2; action++) {
            // buy: action=0, sell: action=1
            int nothing = dp[start+1][action];
            int buy_or_sell = (action)*(prices[start] - fee) + ((1-action)*(-1*prices[start])) + dp[start+1][1-action];
            dp[start][action] = max(nothing, buy_or_sell);
        }
    }
    int res = dp[0][0];
    cout << "Max Profit: " << res << "\n";
}

int main() {
    solve();
    return 0;
}