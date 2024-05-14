// Chessboard and Queens
#include<bits/stdc++.h>
using namespace std;

void queens(
        int col, 
        long long int &ans,
        int n,
        vector<vector<char>> &arr, 
        vector<bool> &leftDiagonal, 
        vector<bool> &rightDiagonal,
        vector<bool> &placedColumns, 
        vector<vector<bool>> &placed
    ) {
        if(col == n) {
            ans++;
            return;
        }
        for(int row=0; row<n; row++) {
            if(
                arr[row][col] == '.' && 
                !leftDiagonal[row-col+n-1] && 
                !rightDiagonal[row+col] && 
                !placedColumns[row]
            ) {
                placed[row][col] = leftDiagonal[row-col+n-1] = rightDiagonal[row+col] = placedColumns[row] = true;
                queens(
                    col+1,
                    ans, 
                    n, 
                    arr, 
                    leftDiagonal, 
                    rightDiagonal, 
                    placedColumns, 
                    placed
                );
                placed[row][col] = leftDiagonal[row-col+n-1] = rightDiagonal[row+col] = placedColumns[row] = false;
            }
        }

}

void solve() {
    int n = 8;
    vector<vector<char>> arr(n, vector<char>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    long long int res = 0;
    vector<bool> leftDiagonal(2*n), rightDiagonal(2*n), placedColumns(n);
    vector<vector<bool>> placed(n, vector<bool>(n));
    queens(
        0, 
        res, 
        n, 
        arr, 
        leftDiagonal, 
        rightDiagonal, 
        placedColumns, 
        placed
    );
    cout << res << "\n";
}
 
int main() {
    // int t;
    // cin >> t;
    // while(t--) solve();
    solve();
}