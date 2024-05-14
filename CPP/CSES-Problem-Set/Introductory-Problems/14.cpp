// Tower of Hanoi
#include<bits/stdc++.h>
using namespace std;

void hanoi(vector<pair<int, int>> &arr, int n, int src, int dest, int aux) {
    if(n == 0) return;
    hanoi(arr, n-1, src, aux, dest);
    arr.push_back({src, dest});
    hanoi(arr, n-1, aux, dest, src);
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    hanoi(arr, n, 1, 3, 2);
    cout << arr.size() << "\n";
    for(auto it: arr) {
        cout << it.first << " " << it.second << "\n";
    }
}
 
int main() {
    // int t;
    // cin >> t;
    // while(t--) solve();
    solve();
}