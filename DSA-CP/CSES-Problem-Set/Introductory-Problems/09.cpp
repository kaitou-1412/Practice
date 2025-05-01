// Bit Strings
#include<bits/stdc++.h>
using namespace std;

long long int numOfBitStrings(int n, vector<long long int> &dp) {
    if(dp[n]) return dp[n];
    long long int mod = 1e9 + 7;
    if(n == 1) return 2;
    return dp[n] = ((1 + n%2) * (numOfBitStrings(n/2, dp)%mod) * (numOfBitStrings(n/2, dp)%mod))%mod;
}

int main() {
    int n;
    cin >> n;
    vector<long long int> dp(n+1, 0);
    cout << numOfBitStrings(n, dp) << "\n";
}