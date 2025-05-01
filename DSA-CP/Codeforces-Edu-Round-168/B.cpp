#include<bits/stdc++.h>
using namespace std;

int main() {
    // Make Three Regions
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        char s[2][n];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> s[i][j];
            }
        }
        int res = 0;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++) {
                if(j>0 && j<n-1 && s[i][j] == '.') {
                    if(s[i][j-1] == 'x' && s[i][j+1] == 'x') {
                        if(s[(i+1)%2][j-1] == '.' && s[(i+1)%2][j+1] == '.') {
                            res++;
                        }
                    }
                }
            }
        }
        cout << res << '\n';
    }
}