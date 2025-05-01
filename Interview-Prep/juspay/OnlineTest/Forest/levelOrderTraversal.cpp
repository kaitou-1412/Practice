#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(int parent[], int n) {
    vector<vector<int>> res;
    vector<int> adj[n];
    queue<int> q;
    for(int child=0; child<n; child++) {
        int par = parent[child];
        if(par == -1) {
            q.push(child);
        } 
        else adj[par].push_back(child);
    }

    while(!q.empty()) {
        int sz = q.size();
        set<int> s;
        while(sz--) {
            int node = q.front();
            s.insert(node);
            q.pop();
            for(int adjNode: adj[node]) {
                q.push(adjNode);
            }
        }
        vector<int> v(s.begin(), s.end());
        res.push_back(v);
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
        vector<vector<int>> ans = solve(Parent, N);
        for(int i=0; i<ans.size(); i++) {
            for(int j=0; j<ans[i].size(); j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
}

/*
question no 2:

==================

You are given a forest (it may contain a single tree or more than one tree) with N nodes.

Each node is given an integer value 0 to (N­-1).

You have to find:

==================

Level order traversal: print nodes at every level of the forest.

N can be very large. Aim for an algorithm with a time complexity of O(N).

INPUT FORMAT

==============

An integer T, denoting the number of testcases, followed by 2T lines, as each testcase will contain 2 lines.

First line of each testcase has the value of N.

Second line of each testcase has list of N values where the number at index i is the parent of node i. The parent of root is -1. ( The index has the range [0, N­-1] ).

OUTPUT FORMAT

================

For each testcase given, Suppose m is the height of tree, then next m lines must contain the nodes of that level in ascending order separated by space. After printing level order traversal of each testcase, print a new line.

SAMPLE INPUT

================

2

6

5 -1 1 1 5 2

13

4 3 -1 -1 1 2 7 3 1 4 2 1 2

SAMPLE OUTPUT

===============

1

2 3

5

0 4

2 3

1 5 7 10 12

4 6 8 11

0 9
*/