#include<bits/stdc++.h>
using namespace std;


int solve(int edges[], int N) {    
    int maxWeight = INT_MIN, res;
    
    // build weight array
    vector<int> weight(N, 0);
    for(int i = 0; i < N; i++){
        if(edges[i] != -1) {
            weight[edges[i]] += i;
        }
    }

    for(int i = 0; i < N; i++){
        if(maxWeight < weight[i]) {
            maxWeight = weight[i];
            res = i;
        }
    }

    return res;
}

int main() {
    int N;
    cin >> N;
    int Edge[N];
    for(int i=0; i<N; i++) cin >> Edge[i];
    cout << solve(Edge, N) << "\n";
}

/*
Problem Description :- Maximum Weight Node
Given a maze with N cells. Each cell may have multiple entry points but not more than one exit(i.e entry/exit points are unidirectional doors like valves).

You are given an array Edge[] of N integers, where Edge[i] contains the cell number that can be reached from of cell i in one step. Edge[i] is -1 if the ith cell doesn’t have an exit.

The task is to find :- the node number of maximum weight node(Weight of the node is the sum of node numbers of all nodes pointing to that node).

Note:- The cells are named with an integer value from 0 to N-1. If there is no node pointing to the ith node then weight of the ith node is zero.

INPUT FORMAT :-

The first line contains the number of cells N.
The second line has a list of N values of the edge[ ] array, where edge[i] conatins the cell number that can be reached from cell 'i' in one step. edge[i] is -1 if the ith doesn't have ans exit.
OUTPUT FORMAT :

First line denotes the node number with maximum weight node.
Sample Input :
23
4 4 1 4 13 8 8 8 0 8 14 9 15 11 -1 10 15 22 22 22 22 22 21

Sample Output :
22
*/