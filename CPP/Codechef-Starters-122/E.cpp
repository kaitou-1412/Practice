#include<bits/stdc++.h>
using namespace std;

int main() {
    // Matrix Modulo
    // https://www.codechef.com/viewsolution/1046445902
    const int mod = 1e9 + 7;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> matrix[i][j];
            }
        }

    }
}