// A. Cards with Numbers
#include<bits/stdc++.h>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

void solve() {
    int n, a;
    in >> n;
    unordered_map<int, vector<int>> mp;
    vector<int> pair(5001, 0);
    for(int i=1; i<=2*n; i++) {
        in >> a;
        mp[a].push_back(i);
        pair[a] = mp[a].size()%2;
    }
    bool poss = true;
    for(int x=1; x<=5000; x++) {
        if(pair[x] == 1) {
            poss = false;
            break;
        }
    }
    if(!poss) out << "-1\n";
    else {
        for(auto it: mp) {
            int a = it.first;
            vector<int> pos = it.second;
            for(int i=0; i<pos.size(); i+=2) out << pos[i] << " " << pos[i+1] << "\n";
        }
    }
}

int main() {
    solve();
    return 0;
}
