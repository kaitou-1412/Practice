#include<bits/stdc++.h>
using namespace std;

int dijkstra(vector<pair<int, int>> adj[], int n, int source, int dest) {
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
    return res[dest];    
}

int main() {
    int N;
    cin >> N;
    int memberId[N];
    unordered_map<int, int> memberIndexMap;
    for(int i=0; i<N; i++) {
        cin >> memberId[i];
        memberIndexMap[memberId[i]] = i;
    }
    int E;
    cin >> E;
    vector<pair<int, int>> adj[N];
    for(int i=0; i<E; i++) {
        int follower, following, time;
        cin >> follower >> following >> time;
        adj[memberIndexMap[follower]].push_back(make_pair(memberIndexMap[following], time));                
    }
    int A, B;
    cin >> A >> B;
    int ans = dijkstra(adj, N, memberIndexMap[A], memberIndexMap[B]);
    cout << ans << "\n";
}

/*
js newbie "A" wants to learn React from "B" and wants to know in his newtwork who can introduce him to B in the shortest time period.

Input format:
Total Members in UI friend Network = N
MemberId1 = N1
MemberId2 = N2
MemberId3 = N3
MemberIdN = Nn

Output format:
shortest time A takes to reach B

Sample Input:
4
2
5
7
9
4
2 9 2
7 2 3
7 9 7
9 5 1
7
9

Sample Output:
5
*/