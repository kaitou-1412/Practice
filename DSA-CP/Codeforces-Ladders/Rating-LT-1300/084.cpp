// A. Domino
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y, total_number_of_odds = 0, x_odds = 0, y_odds = 0, flag = 0;
    cin >> n;
    while(n--)
    {
        cin >> x >> y;
        if(x%2 != 0 && y%2 != 0)
            flag++;
        if(x%2 != 0)
        {
            x_odds++;
            total_number_of_odds++;
        }
        if(y%2 != 0)
        {
            y_odds++;
            total_number_of_odds++;
        }
    }
    int a = x_odds%2, b = y_odds%2;
    if(a == 0 && b == 0)
        cout << "0\n";
    else if(total_number_of_odds%2 != 0 || (flag%2 != 0 && x_odds == y_odds && x_odds == flag))
        cout << "-1\n";
    else
        cout << "1\n";

}

int main() {
    solve();
    return 0;
}
