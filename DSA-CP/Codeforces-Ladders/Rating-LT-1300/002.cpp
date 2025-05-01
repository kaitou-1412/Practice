// A. Beautiful Matrix
#include<bits/stdc++.h>
using namespace std;

int main() {
    int sum, ele;
    for(int i = 0; i<5; i++) {
        for(int j = 0; j<5; j++) {
            cin >> ele;
            if(ele == 1) 
                sum = abs(2-i) + abs(2-j);
        }
    }
    cout << sum << "\n";
    return 0;
}
