#include<bits/stdc++.h>
using namespace std;

class Tree {
    public:
        int data;
        vector<Tree*> children;
        Tree(int data) {
            this->data = data;
        }
};

pair<pair<bool, bool>, int> lca(Tree* root, int x, int y) {
    pair<pair<bool, bool>, int> ans = make_pair(make_pair(false, false), -1);
    if(!root) return ans;
    if(root->data == x) ans.first.first = true; 
    else if(root->data == y) ans.first.second = true;
    int n = root->children.size();
    for(int i=0; i<n; i++) {
        pair<pair<bool, bool>, int> child = lca(root->children[i], x, y);
        ans.first.first |= child.first.first;
        ans.first.second |= child.first.second;
        if(child.second != -1) ans.second = child.second;
    }
    if(ans.first.first && ans.first.second && ans.second == -1) ans.second = root->data;
    return ans;
}

int solve(int parent[], int n, int n1, int n2) {
    Tree* root = new Tree(-1);
    unordered_map<int, Tree*> dataNodeMap;
    dataNodeMap[-1] = root;
    for(int child=0; child<n; child++) dataNodeMap[child] = new Tree(child);
    int countRoot = 0;
    for(int child=0; child<n; child++) {
        int par = parent[child];
        if(par == -1) countRoot++;
        dataNodeMap[par]->children.push_back(dataNodeMap[child]);
    }
    pair<pair<bool, bool>, int> ans = lca(root, n1, n2);
    return ans.second;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        int Parent[N];
        for(int i=0; i<N; i++) cin >> Parent[i];
        int x1, x2;
        cin >> x1 >> x2;
        cout << solve(Parent, N, x1, x2) << "\n";
    }
}

/*
Question 03:
-------------

You are given a forest (it may contain a single tree or more than one tree) with N nodes.

Each node is given an integer value 0 to (N­-1).

You have to find:

==================

Nearest common ancestor of two given nodes x1 and x2.

N can be very large. Aim for an algorithm with a time complexity of O(N).

INPUT FORMAT

-------------

An integer T, denoting the number of testcases, followed by 3T lines, as each testcase will contain 3 lines.

First line of each testcase has the value of N.

Second line of each testcase has list of N values where the number at index i is the parent of node i. The parent of root is -1. ( The index has the range [0, N­-1] ).

Third line for each testcase contains two integers within the range of [0,N­-1] whose common ancestor you have to find.

OUTPUT FORMAT

==============

For each testcase given, output a single line that has the nearest common ancestor to two given nodes x1 and x2. If a common ancestor is not present then output '-1'.

SAMPLE INPUT

-------------

2

6

5 -1 1 1 5 2

0 3

13

4 3 -1 -1 1 2 7 3 1 4 2 1 2

8 5

SAMPLE OUTPUT

================

1

-1
*/