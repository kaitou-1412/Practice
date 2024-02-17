#include<bits/stdc++.h>
using namespace std;

int solve(int edges[], int node1, int node2){
    int x = node1, y = node2;
    unordered_set<int> pathX, pathY;
    while(true) {
        // cycle condition or both have reached an end.
        if (pathX.find(x) != pathX.end() || pathY.find(y) != pathX.end() || (x == -1 && y == -1)) {
            return -1;
        }
        
        // if current node is already encountered in other node's path
        if (pathY.find(x) != pathY.end()) {
            return x;
        }
        
        // if current node is already encountered in other node's path
        if (pathX.find(y) != pathX.end()){
            return y;
        }

        // if the node hasn't reached the end move by one step 
        if (x != -1) {
            pathX.insert(x);
            x = edges[x];
        }

        // if the node hasn't reached the end move by one step
        if (y != -1) {
            pathY.insert(y);
            y = edges[y];
        }
    }
}

int main() {
    int N;
    cin >> N;
    int Edge[N];
    for(int i=0; i<N; i++) cin >> Edge[i];
    int node1, node2;
    cin >> node1 >> node2;
    cout << solve(Edge, node1, node2) << "\n";
}

/*
Problem Description :- Nearest Meeting Cell
You are given a maze with N cells. Each cell may have multiple entry points but not more than one exit (i.e. entry/exit points are unidirectional doors like valves). The cells are named with an integer from 0 to N-1.

You are given an array Edge[] of N integers, where Edge[i] contains the cell number that can be reached from of cell i in one step. Edge[i] is -1 if the ith cell doesn’t have an exit.

The task is to find :- Nearest meeting cell : Given any two cells - C1, C2, find the closest cell Cm that can be reached from both C1 and C2.

Note:- The cells are named with an integer value from 0 to N-1. If there is no node pointing to the ith node then weight of the ith node is zero.

INPUT FORMAT :-

The first line contains the number of cells N.
The second line has a list of N values of the edge[ ] array, where edge[i] conatins the cell number that can be reached from cell 'i' in one step. edge[i] is -1 if the ith doesn't have an exit.
Third line for each testcase contains two cell numbers whose nearest meeting cell needs to be found. (return -1 if there is no meeting cell from tw.
OUTPUT FORMAT :
1.Output a single line that denotes the nearest meeting cell (NMC).

Sample Input :
23
4 4 1 4 13 8 8 8 0 8 14 9 15 11 -1 10 15 22 22 22 22 22 21
9 2

Sample Output :
4
*/