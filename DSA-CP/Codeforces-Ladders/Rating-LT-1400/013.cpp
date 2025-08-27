// A. Cakeminator
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int r, c, cakes = 0;
    cin >> r >> c;
    char a[r][c];
    vector<int> row(r, 0), column(c, 0);
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 'S')
            {
                row[i] = 1;
                column[j] = 1;
            }
        }
    }
    int number_of_row_blocks = 0, number_of_column_blocks = 0;
    for(int i = 0; i < r; i++)
    {
        if(row[i] == 0)
            number_of_row_blocks++;
    }
    for(int j = 0; j < c; j++)
    {
        if(column[j] == 0)
            number_of_column_blocks++;
    }
    cakes += (r*number_of_column_blocks) + (c*number_of_row_blocks) - (number_of_row_blocks*number_of_column_blocks);
    cout << cakes << "\n";
}

int main() {
    solve();
    return 0;
}
