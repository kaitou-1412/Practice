// A. Arrival of the General
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, counter = 0;
    cin >> n;
    int a[n];
    cin >> a[0];
    int max_index = 0;
    for(int i = 1; i<n; i++) {
        cin >> a[i];
        if(a[i] > a[max_index])
            max_index = i;
    }
    counter += max_index;
    int min_index = n-1;
    for(int i = n-2; i>=0; i--) {
        if(a[i] < a[min_index])
            min_index = i;
    }
    if(min_index < max_index)
        min_index++;
    counter += n-1-min_index;
    cout << counter << "\n";
}

int main() {
    solve();
    return 0;
}
