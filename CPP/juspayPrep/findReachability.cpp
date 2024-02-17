#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[], int dest, bool &found) {
    if(found) return;
    vis[node] = 1;
    if(node == dest) {
        found = true;
        return;
    }
    for(int neighbour: adj[node]) {
        if(!vis[neighbour]) {
            dfs(neighbour, vis, adj, dest, found);
        }
    }
}

int solve(vector<int> adj[], int n, int src, int dest) {
    bool found = false;
    vector<int> vis(n, 0);
    dfs(src, vis, adj, dest, found);
    return found ? 1 : 0;
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
    int ans = solve(adj, N, memberIndexMap[A], memberIndexMap[B]);
    cout << ans << "\n";
}

/*
Find Reachability
JS newbie "A" wants to check if he can reach out to a react expert "B" using his network of react developers. If he can then return 1 else return 0. 

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
If A can reach B then output is 1, else 0.

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
1
*/