// A. Beautiful Year
#include<bits/stdc++.h>
using namespace std;

bool check_distinct_year(int y) {
    int mp[10] = {0};
    while(y>0) {
        mp[y%10]++;
        if(mp[y%10]>1) return false;
        y = y/10;
    }
    return true;
}

int main() {
    int y;
    cin >> y;
    int res;
    for(res = y+1; res<=9012; res++) {
        if(check_distinct_year(res)) break;
    }  
    cout << res << "\n";
}