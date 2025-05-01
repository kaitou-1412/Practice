// Two Knights
#include<bits/stdc++.h>
using namespace std;

// Number of positions knight can be attacked from
// int getChances(long long int i, long long int j, long long int n) {
//     if(n < 3 || (n == 3 && i == 2 && j == 2)) return 0;
//     if(n == 3) return 2;
//     if(i >= 3) return 8;
//     if(i == 2 && j > 2) return 6;
//     if((i+j) == 2) return 2;
//     if((i+j) == 3) return 3;
//     return 4;
// }

// int getReps(long long int i, long long int j, long long int n) {
//     long long int m = (n+1)/2;
//     if(n%2 && i == m && j == m) return 1;
//     if((n%2 && j == m) || i == j) return 4;
//     return 8;
// }

long long int solve(long long int n, vector<long long int> &dp) {
    // if(dp[n]) return dp[n];
    // long long int m = (n+1)/2, res = 0;
    // if(n>8) {
    //     dp[n] = dp[n-2] + 2*(2*n*n - 4*n + 3)*(n - 1) - (88 - (n%2)*16 + 32*((n-7)/2));
    //     return dp[n]; 
    // }
    // for(long long int i=1; i<=m; i++) {
    //     for(long long int j=i; j<=m; j++) {
    //         int chances = getChances(i, j, n);
    //         int reps = getReps(i, j, n);
    //         long long int curr = (((n*n) - 1 - chances)*reps)/2;
    //         res += curr;
    //     }
    // }
    // dp[n] = res;
    // return res;
    return (((n*n)*(n*n-1)/2) - 4*(n-1)*(n-2));
}

int main() {
    long long int n;
    cin >> n;
    vector<long long int> dp(10005, 0);
    for(long long int k=1; k<=n; k++) cout << solve(k, dp) << "\n";
}