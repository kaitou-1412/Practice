// Rearrange K Substrings to Form Target String
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        if(n%k != 0) return false;
        int sz = n/k;
        unordered_map<string, int> mp;
        for(int start=0; start<n; start += sz) {
            string sub = s.substr(start, sz);
            mp[sub]++;
        }
        for(int start=0; start<n; start += sz) {
            string sub = t.substr(start, sz);
            if(mp[sub] == 0) return false;
            mp[sub]--;
        }
        return true;
    }
};