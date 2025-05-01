// Trailing Zeros
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long int n, n2, n5;
    cin >> n;
    n2 = n;
    n5 = n;
    int res2 = 0, res5 = 0, res;
    while(n2 != 0 && n5 != 0) {
        n2 /= 2;
        n5 /= 5;
        res2 += n2;
        res5 += n5; 
    }
    res = min(res2, res5); 
    cout << res << "\n";
}