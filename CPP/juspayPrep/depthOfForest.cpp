#include<bits/stdc++.h>
using namespace std;

int solve(int parent[], int n) {
    long long res = -1;
    vector<int> adj[n];
    queue<int> q;
    unordered_map<int, int> levelCountMap;
    for(int child=0; child<n; child++) {
        int par = parent[child];
        if(par == -1) {
            q.push(child);
        } 
        else adj[par].push_back(child);
    }

    int maxDepth = -1;
    while(!q.empty()) {
        int sz = q.size();
        maxDepth++;
        levelCountMap[maxDepth] = sz;
        while(sz--) {
            int node = q.front();
            q.pop();
            for(int adjNode: adj[node]) {
                q.push(adjNode);
            }
        }
    }

    int maxCount = INT_MIN;
    for(int depth=maxDepth; depth>=0; depth--) {
        if(maxCount < levelCountMap[depth]) {
            maxCount = levelCountMap[depth];
            res = depth;
        }
    }
    
    return res;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        int Parent[N];
        for(int i=0; i<N; i++) cin >> Parent[i];
        cout << solve(Parent, N) << "\n";
    }
}

/*
question no: 1

===================

You are given a forest (it may contain a single tree or more than one tree) with N nodes.

Each node is given an integer value 0 to (N­-1).

You have to find:

===================

The depth of forest at which maximum number of nodes are present.

N can be very large. Aim for an algorithm with a time complexity of O(N).

INPUT FORMAT

=================

An integer T, denoting the number of testcases, followed by 2T lines, as each testcase will contain 2 lines.

First line of each testcase has the value of N.

Second line of each testcase has list of N values where the number at index i is the parent of node i. The parent of root is -1. ( The index has the range [0, N­-1] ).

OUTPUT FORMAT

===============

For each testcase given, output a single line that has the depth of forest at which maximum number of nodes are present. If multiple depths has same number of nodes, then deepest depth should be selected.

SAMPLE INPUT

==============

2

6

5 -1 1 1 5 2

13

4 3 -1 -1 1 2 7 3 1 4 2 1 2

SAMPLE OUTPUT

====================

3

1
*/