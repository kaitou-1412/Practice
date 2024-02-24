#include<bits/stdc++.h>
using namespace std;

bool noMatchingBitValues(int i, int j, vector<long long> &a) {
    for(int digit=0; digit<32; digit++) {
        int count = 0;
        for(int index = i; index<=j; index++) {
            if(a[index] & (1ll << digit)){
                count++;
            }
            if(count > 1) return false;
        }
    }
    return true;
}

int main() {
    // Transformation Cost
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> binary(32, 0);
        int total_ones = 0, firstOneIndex = -1, lastZeroBeforeLastOneIndex = -1;
        for(int i=0; i<=31; i++) {
            if(n == 0) break;
            binary[i] = n%2;
            if(binary[i] == 1) {
                total_ones++;
                if(firstOneIndex == -1) firstOneIndex = i;
            } else {
                if(total_ones>=1) lastZeroBeforeLastOneIndex = i;
            }
            n /= 2;
        }
        int res = 0;
        if(total_ones<=1) {
            lastZeroBeforeLastOneIndex = -1;
        }
        if(total_ones >= 2 && lastZeroBeforeLastOneIndex != -1) {
            res |= (1 << firstOneIndex);
            for(int i=firstOneIndex+1; i<lastZeroBeforeLastOneIndex; i++) {
                if(binary[i] == 0) {
                    res |= (1<<i); 
                }
            }
        }
        cout << res << '\n';
    }
}