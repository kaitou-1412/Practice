// A. Panoramix's Prediction
#include<bits/stdc++.h>
using namespace std;

int find_next_prime(int n) {
    if(n == 2) return 3;
    else if(n == 3) return 5;
    int res = n+1;
    while(res<=54) {
        bool  is_prime = true;
        for(int div=2; div<res; div++) {
            if(res%div == 0) {
                is_prime = false;
                break;
            }
        }
        if(is_prime) break;
        res++;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    cout << (find_next_prime(n) == m ? "YES" : "NO") << "\n";
}

int main() {
    solve();
    return 0;
}