// Two Sets
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n%4 != 0 && (n+1)%4 != 0) {
        cout << "NO\n";
        return 0;
    } 
    cout << "YES\n";
    cout << (n + n%2)/2 - n%2 << "\n";
    for(int i=1; i<=(n + n%2)/4 - n%2; i++) cout << i << " ";
    for(int i=3*(n + n%2)/4 + 1 - n%2; i<=n; i++) cout << i << " ";
    cout << "\n";
    cout << (n + n%2)/2 << "\n";
    for(int i=(n + n%2)/4 + 1 - n%2; i<=3*(n + n%2)/4 - n%2; i++) cout << i << " ";
    cout << "\n";
}