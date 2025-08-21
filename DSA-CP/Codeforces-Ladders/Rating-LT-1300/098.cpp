// B. Sort the Array
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, l = 0, r = 0, found = 0;
    cin >> n;
    vector<int> a(n), v(n), isEqual(n);
    for(int i=0; i<n; i++) { cin >> a[i]; v[i] = a[i]; }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++) {
        isEqual[i] = (a[i]!=v[i]) ? 1 : 0;
        if(isEqual[i] == 1 && found == 0) {
            found = 1;
            l = i+1;
        }
        if(i>0 && isEqual[i] == 1) {
            isEqual[i] += isEqual[i-1];
            r = max(r, i+1);
        }
    }
    for(int i=0; l!=0 && i<l-1; i++) {
        if(a[i] != v[i]) {
            l = 0;
            break;
        }
    }
    for(int i=l-1; l!=0 && i<=r-1; i++) {
        if(a[i] != v[r+l-2-i]) {
            l = 0;
            break;
        }
    }
    for(int i=r; l!=0 && i<n; i++) {
        if(a[i] != v[i]) {
            l = 0;
            break;
        }
    }
    if(l == 0 && found == 1) {
        cout << "no\n";
    } else if(l == 0 && found == 0) {
        l = 1;
        r = 1;
        cout << "yes\n";
        cout << l << " " << r << "\n";
    } else {
        cout << "yes\n";
        cout << l << " " << r << "\n";
    }
}

int main() {
    solve();
    return 0;
}
