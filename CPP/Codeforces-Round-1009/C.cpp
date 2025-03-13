#include<bits/stdc++.h>
using namespace std;

bool is_non_degenerate_triangle(int a, int b, int c) {
    return (a+b>c) && (b+c>a) && (c+a>b);
}

bool is_power_of_2(int n) {
    return (n&(n-1)) == 0;
}

int main() {
    // C. XOR and Triangle
    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        int res = -1;
        if(!is_power_of_2(x) && !is_power_of_2(x+1)) {
            res = 0;
            bool first_set_bit = false;
            int temp = x;
            for(int i=1; i<x; i++) {
                if(is_non_degenerate_triangle(x, i, x^i)) {
                    res = i;
                    break;
                }
            }
        }
        cout << res << "\n";
    }
}