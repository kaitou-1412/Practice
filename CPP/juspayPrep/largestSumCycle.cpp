#include<bits/stdc++.h>
using namespace std;

void findTopo(int node, vector<int> adj[], vector<int> &vis, vector<int> &temp) {
    vis[node] = 1;
    for(auto adjNode: adj[node]) {
        if(!vis[adjNode]){
            findTopo(adjNode, adj, vis, temp);
        }
    }
    temp.push_back(node);
}

void dfs(int node, vector<int> revAdj[], vector<int> &vis, long long &sum, long long &len) {
    vis[node] = 1;
    sum += node;
    len++;
    for(auto adjNode: revAdj[node]) {
        if(!vis[adjNode]){
            dfs(adjNode, revAdj, vis, sum, len);
        }
    }
}


pair<int, int> solve(int edges[], int N) {
    long long res = -1, maxLen = 0;
    
    // apply kosaraju's to find and find sum
    vector<int> adj[N];
    for(int i = 0; i < N; i++) {
        if(edges[i] < 0) continue;
        adj[i].push_back(edges[i]);
    }
    
    // find topologcal sort
    vector<int> temp;
    vector<int> vis(N, 0);
    for(int i = 0; i < N; i++){
        if(!vis[i]){
            findTopo(i, adj, vis, temp);
        }
    }
    reverse(temp.begin(), temp.end());

    //reverse all the edges
    vector<int> revAdj[N];
    for(int i = 0; i < N; i++){
        if(edges[i] < 0) continue;
        revAdj[edges[i]].push_back(i);
    }
    
    //apply dfs again to find scc
    //single node should not be considered in sum
    fill(vis.begin(), vis.end(), 0);
    for(auto node: temp){
        long long sum = 0, len = 0;
        if(!vis[node]){
            dfs(node, revAdj, vis, sum, len);
        }
        if(sum - node > 0) {
            res = max(res, sum);
            maxLen = max(maxLen, len);
        }
    }

    return make_pair(res, maxLen);
}

int main() {
    int N;
    cin >> N;
    int Edge[N];
    for(int i=0; i<N; i++) cin >> Edge[i];
    pair<int, int> ans = solve(Edge, N);
    // cout << "Sum: " << ans.first << " Length: " << ans.second << "\n";
    cout << ans.second << "\n";
}

/*
Problem Description :- Largest Sum Cycle
Given a maze with N cells. Each cell may have multiple entry points but not more than one exit(i.e entry/exit points are unidirectional doors like valves).

You are given an array Edge[] of N integers, where Edge[i] contains the cell number that can be reached from of cell i in one step. Edge[i] is -1 if the ith cell doesn’t have an exit.

The task is to find :- the sum of the largest sum cycle in the maze(Sum of a cycle is the sum of node number of all nodes in that cycle).

Note:- The cells are named with an integer value from 0 to N-1. If there is no node pointing to the ith node then weight of the ith node is zero.

INPUT FORMAT :-

The first line contains the number of cells N.
The second line has a list of N values of the edge[ ] array, where edge[i] conatins the cell number that can be reached from cell 'i' in one step. edge[i] is -1 if the ith doesn't have ans exit.
OUTPUT FORMAT :

First line denotes length of the largest cycle..
Sample Input :
23
4 4 1 4 13 8 8 8 0 8 14 9 15 11 -1 10 15 22 22 22 22 22 21

Sample Output :
6
*/