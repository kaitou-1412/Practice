#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<pair<int, int>> adj[], int n, int source) {
    vector<int> res(n, INT_MAX);
    res[source] = 0;
    set<pair<int, int>> st;
    st.insert({0, source});
    while(!st.empty()) {
        auto set_begin = *(st.begin());
        int node_dist = set_begin.first, node = set_begin.second;
        st.erase(set_begin);
        for(auto it: adj[node]) {
            int neighbour = it.first, dist = it.second;
            if(node_dist != INT_MAX && node_dist + dist < res[neighbour]) {
                if(res[neighbour] != INT_MAX) st.erase({res[neighbour], neighbour});
                res[neighbour] = node_dist + dist;
                st.insert({res[neighbour], neighbour});
            }
        }
    }
    for(int i=0; i<n; i++) if(res[i] == INT_MAX) res[i] = -1;
    return res;    
}

int solve(int edges[], int n, int node1, int node2) {
    vector<pair<int, int>> adj[n];
    for(int i=0; i<n; i++) {
        adj[i].push_back(make_pair(edges[i], 1));
    }
    vector<int> dist1 = dijkstra(adj, n, node1);
    vector<int> dist2 = dijkstra(adj, n, node2);
    int node = -1;
    int minDist = INT_MAX;
    for(int i=0; i<n; i++) {
        // if node is not accessible from any of them ignore it
        if(dist1[i] == -1 || dist2[i] == -1) continue;
        if(dist1[i] + dist2[i] < minDist) {
            minDist = dist1[i] + dist2[i]; 
            node = i;
        } 
    }        
    return node;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        int Edge[N];
        for(int i=0; i<N; i++) cin >> Edge[i];
        int node1, node2;
        cin >> node1 >> node2;
        cout << solve(Edge, N, node1, node2) << "\n";
    }
}

/*
Problem Description :- Nearest Meeting Cell
You are given a maze with N cells. Each cell may have multiple entry points but not more than one exit (i.e. entry/exit points are unidirectional doors like valves). The cells are named with an integer from 0 to N-1.

You are given an array Edge[] of N integers, where Edge[i] contains the cell number that can be reached from of cell i in one step. Edge[i] is -1 if the ith cell doesn’t have an exit.

The task is to find :- Nearest meeting cell : Given any two cells - C1, C2, find the closest cell Cm that can be reached from both C1 and C2.

Note:- The cells are named with an integer value from 0 to N-1. If there is no node pointing to the ith node then weight of the ith node is zero.

INPUT FORMAT :-
The first line contains the number of test cases.
For each test case:
The first line contains the number of cells N.
The second line has a list of N values of the edge[ ] array, where edge[i] conatins the cell number that can be reached from cell 'i' in one step. edge[i] is -1 if the ith doesn't have an exit.
Third line for each testcase contains two cell numbers whose nearest meeting cell needs to be found. (return -1 if there is no meeting cell from tw.

OUTPUT FORMAT :
1.Output a single line that denotes the nearest meeting cell (NMC).

Sample Input :
1
23
4 4 1 4 13 8 8 8 0 8 14 9 15 11 -1 10 15 22 22 22 22 22 21
9 2

Sample Output :
4
*/