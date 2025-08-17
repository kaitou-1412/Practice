// A. Rank List
#include<bits/stdc++.h>
using namespace std;

bool comp(const pair<int, int> &v1, const pair<int, int> &v2) {
    int p1 = v1.first, t1 = v1.second, p2 = v2.first, t2 = v2.second;
    if(p1==p2) return t1<t2;
    return p1>p2;
}

void solve() {
    int n, k, p, t;
    cin >> n >> k;
    unordered_map<int, int> rank_count;
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++) {
        cin >> p >> t;
        v.push_back({p, t});
    }
    sort(v.begin(), v.end(), comp);
    for(int i=0; i<n; i++) {
        int rank = i+1;
        rank_count[rank] = 1;
        int j = i;
        if(j>0 && v[j].first == v[j-1].first && v[j].second == v[j-1].second) rank_count[rank] = rank_count[rank-1] + 1;
        while(j>0 && v[j].first == v[j-1].first && v[j].second == v[j-1].second) {
            rank_count[rank-1]++;
            j--;
            rank--;
        }
    }
    cout << rank_count[k] << "\n";
}

int main() {
    solve();
    return 0;
}
