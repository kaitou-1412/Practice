// A. Boys and Girls
#include<bits/stdc++.h>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

void solve() {
    int n, m;
    in >> n >> m;
    int mn = min(n, m);
    string res = "";
    for(int i=0; i<mn; i++) res += "GB";
    for(int i=0; i<n-mn; i++) res = "B" + res;
    for(int i=0; i<m-mn; i++) res += "G";
    out << res << "\n";
}

int main() {
    solve();
    return 0;
}
