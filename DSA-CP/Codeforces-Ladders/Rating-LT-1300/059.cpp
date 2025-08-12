// B. Airport
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int num, maxCost = 0, minCost = 0;
    for(int i = 0; i<m; i++) {
        cin >> num;
        minHeap.push(num);
        maxHeap.push(num);
    }
    int j = 0;
    while(!minHeap.empty()) {
        int cost = minHeap.top();
        minHeap.pop();
        j++;
        if(j>n) break;
        minCost += cost;
        if(cost>1) minHeap.push(cost-1);
    }
    j = 0;
    while(!maxHeap.empty()) {
        int cost = maxHeap.top();
        maxHeap.pop();
        j++;
        if(j>n) break;
        maxCost += cost;
        if(cost>1) maxHeap.push(cost-1);
    }
    cout << maxCost << " " << minCost << "\n";
}

int main() {
    solve();
    return 0;
}
