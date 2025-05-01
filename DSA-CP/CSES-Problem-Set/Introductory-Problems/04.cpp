// Increasing Array
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    long long int res = 0;
    for(int i=1; i<n; i++) {
        if(a[i-1]>a[i]) {
            res += a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }
    cout << res << "\n";
}