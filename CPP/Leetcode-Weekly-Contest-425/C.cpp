// Minimum Array Sum
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[110][110][110];
    int fun(vector<int> &a, int k, int op1, int op2, int i, int n) {
        if(i == n) return 0;
        if(dp[i][op1][op2] != -1) return dp[i][op1][op2];
        int num1 = INT_MAX, num2 = INT_MAX, num3 = INT_MAX, num4 = INT_MAX; 
        num1 = a[i] + fun(a, k, op1, op2, i+1, n);
        if(op1>0) num2 = ((a[i]+1)/2) + fun(a, k, op1-1, op2, i+1, n); 
        if(op2>0 && a[i]>=k) num3 = a[i]-k + fun(a, k, op1, op2-1, i+1, n); 
        if(op1>0 && op2>0){
            int p = a[i];
            int na = (a[i]+1)/2;
            if(na>=k) na -=k;
            if(p>=k) p -= k;
            p = (p+1)/2;
            num4 = min(p, na) + fun(a, k, op1-1, op2-1, i+1, n);
        }
        return dp[i][op1][op2] = min({num1, num2, num3, num4});
    }
    int minArraySum(vector<int> &nums, int k, int op1, int op2) {
        memset(dp, -1, sizeof(dp));
        fun(nums, k, op1, op2, 0, nums.size());
        return dp[0][op1][op2];
    }
};