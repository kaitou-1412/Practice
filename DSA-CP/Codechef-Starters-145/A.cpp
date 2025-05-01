#include<bits/stdc++.h>
using namespace std;

int main() {
    // Gun Master
    int t;
    cin >> t;
    while(t--) {
        int n, d;
        cin >> n >> d;
        int dist, res = 0, curr = 0;
        for(int i=0; i<n; i++) {
            cin >> dist;
            if(dist<=d && curr!=0) {
                res++;
                curr = 0;
            } else if(d<dist && curr!=1) {
                res++;
                curr = 1;
            }
        }
        cout << res << "\n";
    }
}