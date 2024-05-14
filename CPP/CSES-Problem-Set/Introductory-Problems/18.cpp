// Digit Queries
#include<bits/stdc++.h>
using namespace std;

void solve(vector<long long int> &powers) {
    long long int k;
    cin >> k;
    long long int numOfDigits = 0, prevDigitLength = 0, digitLength = 0;
    for(int i=1; i<19; i++) {
        digitLength += i*(powers[i] - powers[i-1]);
        if(k <= digitLength) {
            numOfDigits = i;
            break;
        }
        prevDigitLength = digitLength;
    }
    long long int low = powers[numOfDigits - 1], high = powers[numOfDigits] - 1;
    long long int ans = 0, startPosAns = 0;
    while(low<=high) {
        long long int mid = low + (high-low)/2;
        long long int startPos = numOfDigits*(mid - powers[numOfDigits - 1] ) + prevDigitLength + 1;
        if(startPos<=k) {
            if(mid > ans) {
                ans = mid;
                startPosAns = startPos;
            }
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    string num = to_string(ans);
    cout << num[k-startPosAns] << "\n";
}
 
int main() {
    int t;
    cin >> t;
    vector<long long int> powers(19, 1);
    for(int i=1; i<19; i++) powers[i] = powers[i-1] * 10;
    while(t--) solve(powers);
    // solve();
}