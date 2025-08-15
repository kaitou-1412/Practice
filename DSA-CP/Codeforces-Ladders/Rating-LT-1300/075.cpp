// B. Fence
#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long int n, k, sum = 0, mn = INT_MAX, res = 1;
    cin >> n >> k;
    vector<int> heights(n);
    for(int i=0; i<n; i++) {
        cin >> heights[i];
        sum += heights[i];
        if(i>=k-1) { 
            if(mn>sum) {
                mn = sum;
                res = i-k+2;
            }
            sum -= heights[i-k+1];
        }
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
