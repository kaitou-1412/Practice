#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int par, vector<int> &vis, vector<int> adj[], int dest, vector<int> &res) {
    if(node == dest) {
        if(par != -1) res.push_back(par);
        return;
    }
    for(int neighbour: adj[node]) {
        if(!vis[neighbour]) {
            vis[neighbour] = 1;
            dfs(neighbour, node, vis, adj, dest, res);
            vis[neighbour] = 0;
        }
    }
}

vector<int> solve(vector<int> adj[], int n, int src, int dest) {
    vector<int> res;
    vector<int> vis(n, 0);
    vis[src] = 1;
    dfs(src, -1, vis, adj, dest, res);
    return res;
}

int main() {
    int N;
    cin >> N;
    int memberId[N];
    vector<int> adj[N];
    unordered_map<int, int> memberIndexMap;
    for(int i=0; i<N; i++) {
        cin >> memberId[i];
        memberIndexMap[memberId[i]] = i;
    }
    int E;
    cin >> E;
    for(int i=0; i<E; i++) {
        int follower, following;
        cin >> follower >> following;
        adj[memberIndexMap[follower]].push_back(memberIndexMap[following]);                
    }
    int A, B;
    cin >> A >> B;
    vector<int> ans = solve(adj, N, memberIndexMap[A], memberIndexMap[B]);
    for(int i=0; i<ans.size(); i++) cout << memberId[ans[i]] << " ";
    cout << "\n";
}

/*
The Nagging React newbie 
A Nagging React newbie "A" is constantly troubling React expert "B". React Expert "B" needs to know the minimum set of people following him he needs to remove from his network to stop "B" from reaching out to him.

INPUT FORMAT
Total Members in Ul Friend Network - N
Memberld1 = N1
Memberld2 = N2
Memberld3 = N3
MemberldN = Nn
Total Possible Edges = E
<Follower 1> <Following 1>
<Follower 2> <Following 2>

Follower = A
Following = B
OUTPUT FORMAT
Set of memberld "A" needs to block

Sample Input Sample
4
2
5
7
9
4
2 9
7 2
7 9
9 5
7
9
Output
2 7
*/