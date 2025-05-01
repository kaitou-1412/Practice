#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

bool inside_circle(int x, int y, vector<pair<int, int>> &circle) {
    for(auto it: circle) {
        int c = it.first, r = it.second;
        if((x-c)*(x-c) + y*y <= r*r) {
            return true;
        } 
    }
    return false;
}

int main() {
    // D. Counting Points
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> circle(n);
        int rmax = INT_MIN;
        for(int i=0; i<n; i++) cin >> circle[i].first;
        for(int i=0; i<n; i++) {
            cin >> circle[i].second;
            rmax = max(rmax, circle[i].second);
        }
        sort(circle.begin(), circle.end(), compare);
        long long res = 0;
        map<long long,long long> mp;
        for( int i=0; i<n; i++){
            long long x = circle[i].first, r = circle[i].second;
            for( int j=x-r; j<=x+r; j++){
                long long h = sqrt(r*r - (j-x)*(j-x));
                if(!mp.count(j)){
                    res++;
                }
                res += max(h-mp[j], 0LL)*2;
                mp[j] = max(mp[j], h);
            }
        }
        cout << res << '\n';
    }
}