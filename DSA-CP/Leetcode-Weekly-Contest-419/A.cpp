// Find X-Sum of All K-Long Subarrays I
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> res;
        unordered_map<int, int> freq;
        for(int i=0; i<k; i++) freq[nums[i]]++;
        for(int i=k; i<=nums.size(); i++) {
            vector<pair<int, int>> v(freq.begin(), freq.end());
            sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
                if(a.second == b.second) return a.first > b.first;
                return a.second > b.second;
            });
            int j = x, ans = 0;
            if(freq.size() < x) {
                for(auto it: v) {
                    int num = it.first, f = it.second;
                    ans += num*f;
                }
            } else {
                for(auto it: v) {
                    if(j == 0) break;
                    j--;
                    int num = it.first, f = it.second;
                    ans += num*f;
                }
            }
            res.push_back(ans);
            if(i == nums.size()) break;
            freq[nums[i-k]]--;
            if(freq[nums[i-k]] == 0) freq.erase(nums[i-k]);
            freq[nums[i]]++;
        }
        return res;
    }
};