#include<bits/stdc++.h>
using namespace std;

int main() {
    // ------
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int available = n;
        int p = 1;
        while (available > 0) {
            int take = available - available / 2;
            if (k <= take) {
                cout << p * (2 * k - 1) << '\n';
                break;
            }
            k -= take;
            p *= 2;
            available /= 2;
        }
    }
}