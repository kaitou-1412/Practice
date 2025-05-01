#include<bits/stdc++.h>
using namespace std;

int main() {
    // Vlad and Shapes
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> s(n);
        int min_i = n + 1;
        int min_j = n + 1;
        int max_i = -1;
        int max_j = -1;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            for (int j = 0; j < n; j++) {
                if (s[i][j] == '1') {
                    min_i = min(min_i, i);
                    min_j = min(min_j, j);
                    max_i = max(max_i, i);
                    max_j = max(max_j, j);
                }
            }
        }
        cout << (max_i - min_i == max_j - min_j ? "SQUARE" : "TRIANGLE") << '\n';
    }
}