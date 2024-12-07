// Minimum Positive Sum Subarray
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int> &nums, int l, int r) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        for(int i=1; i<n; i++) prefix[i] = prefix[i-1] + nums[i];
        int res = INT_MAX, end = 0;
        for(int start=0; start<n; start++) {
            end = start + l - 1;
            while(end-start+1<=r && end<n) {
                int sum = (start == 0) ? prefix[end] : prefix[end] - prefix[start-1];
                if(sum>0) res = min(res, sum);
                end++;
            }
        }
        if(res == INT_MAX) return -1;
        return res;
    }
};