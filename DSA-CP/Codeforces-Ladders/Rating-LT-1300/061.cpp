// B. Pashmak and Flowers
#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long int n, b, mini = INT_MAX, maxi = INT_MIN, countMin = 0, countMax = 0;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> b;
        if(b<=mini) {
            if(b == mini) {
                countMin++;
            } else {
                countMin = 1;
                mini = b;
            }
        }
        if(b>=maxi) {
            if(b == maxi) {
                countMax++;
            } else {
                countMax = 1;
                maxi = b;
            }
        }
    }
    long long int maxDiff = maxi - mini, ways = (mini == maxi) ? n*(n-1)/2 : countMin*countMax; 
    cout << maxDiff << " " << ways << "\n";
}

int main() {
    solve();
    return 0;
}
