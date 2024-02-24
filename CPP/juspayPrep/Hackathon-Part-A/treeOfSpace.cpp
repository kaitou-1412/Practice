#include<bits/stdc++.h>
using namespace std;

/* TreeNode is used to store all information 
 (i.e. parent, locked, locked by which id, children, locked descendents) */
struct TreeNode { 
	string name; // name of the node
	int lockedBy; // store locked by which id
	bool isLocked; // is node locked or not
	vector<TreeNode*> children; // store all children or current node
	TreeNode* parent; // parent of current node
	unordered_set<TreeNode*> lockedDescendents; // store node pointer of locked descendents

    /* constructor to create node by 
    passing node's name and partner node pointer. 
    If current node is root node of tree then parent of root will be NULL */
	TreeNode(string nm, TreeNode* par) {  
		name = nm;
		lockedBy = -1; // Initially we are assuming current node is not locked by any id (-1 means not locked by any id)
		parent = par;
		isLocked = false; // node is unlocked
	}

    /* create all the children of current node */
	void addChild(vector<string> &a){
		for(string &nm: a){
			children.push_back(new TreeNode(nm, this));
		}
	}
};

struct MAryTree {
	TreeNode* root; // root of the tree
	unordered_map<string, TreeNode*> nameToTreeNodeMapping; // store node name and node pointer mapping
	
    /* constructor of M-Ary-Tree */
    MAryTree(string name) { 
		root = new TreeNode(name, nullptr);
	}

    /* this method is used to build the tree (Initially). */
	void makeMAryTree(vector<string> &a, int m) {
		queue<TreeNode*> q; // using queue to iterate all node like bfs approach
		int k = 1, i, n = a.size();
		q.push(root); // push root node initially
		while(!q.empty()) { // iterate node (pop node) and push all its children in the queue.
			TreeNode* r = q.front();
			q.pop();
			nameToTreeNodeMapping[r->name] = r;
			vector<string> b;
			for(i=k; i<min(n,k+m); i++) {
				b.push_back(a[i]);
			}
			r->addChild(b);
			for(TreeNode* child: r->children) { // insert all its children ( of recently poped node) in the queue
				q.push(child);
			}
			k = i;
		}
	}

    /* method is used to print tree (for debug purpose). */
	void print(TreeNode *r) {
		if(!r) return;
		cout << "TreeNode -> " << r->name<< " " << r->lockedBy << " " << "\n";
		cout << "Children -> \n";
		for(TreeNode* child: r->children) {
			cout << "       " << child->name << "\n";
		}
		cout << "Locked -> \n";
		for(TreeNode* child: r->lockedDescendents) {
			cout << "       " << child->name << "\n";
		}
		for(TreeNode* child: r->children){
			print(child);
		}
	}

    /* inform all ancestor about its child locking in O(logN base M)
       N is the total no of node in the tree
       M -> M-ary-tree */
	void updateParents(TreeNode* r, TreeNode* curr) { 
		while(r) {
			r->lockedDescendents.insert(curr);
			r = r->parent;
		}
	}

    /* method is required to lock the node which is given in problem statement */
	bool lock(string name, int id) { 
		TreeNode* r = nameToTreeNodeMapping[name]; // fetch the node pointer using its name
		if(r->isLocked || r->lockedDescendents.size()) return false; // check if node is already locked and have any locked descendants than return false (if any condition become true)
		TreeNode* par= r->parent;
		while(par) { // check if any ancestor is locked or not (by any id) if yes than we can't lock current node
			if(par->isLocked) return false;
			par = par->parent;
		}
		updateParents(r->parent, r); // inform all ancestor about its locking in O(logm(n) time)
		r->isLocked = true; // lock the node
		r->lockedBy = id;
		return true;
	}

	bool unlock(string name, int id) {
		TreeNode* r = nameToTreeNodeMapping[name];
		if(!r->isLocked || r->lockedBy != id) return false; // return false if node is unlocked or locked by different id
		TreeNode *par = r->parent;
		while(par) { // inform all Ancestors about its unlocking
			par->lockedDescendents.erase(r);
			par = par->parent;
		}
		r->isLocked = false; // unlock it
		r->lockedBy = -1;
		return true;
	}

	bool upgradeLock(string name, int id) {
		TreeNode* r = nameToTreeNodeMapping[name];
		if(r->isLocked || r->lockedDescendents.empty()) return false; // return false if node is already locked or have 0 locked descendants
		for(TreeNode* ld: r->lockedDescendents) { // check all the descendants are locked by same id or not
			if(ld->lockedBy != id) return false;
		}
		TreeNode* par = r->parent;
		while(par) { // check if any ancestor is locked or not
			if(par->isLocked) return false;
			par = par->parent;
		}
		unordered_set<TreeNode*> stt = r->lockedDescendents;
		for(TreeNode* ld: stt) { // unlock all descendants
			// cout << ld->name << "\n";
			unlock(ld->name, id);
		}
		lock(name, id); // lock current node
		return true;
	}
};

int main() {
    int t;
    cin >> t;
	while(t--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<string> vertices(n);
        for(int i=0; i<n; i++) cin >> vertices[i];
        MAryTree* tree = new MAryTree(vertices[0]);
        tree->makeMAryTree(vertices, m);
        // tree->print(tree->root);
        while(q--) {
            int opType, id;
            string name;
            cin >> opType >> name >> id;
            bool res = false;
            switch (opType) {
                case 1:
                    res = tree->lock(name, id);
                    break;
                case 2:
                    res = tree->unlock(name, id);
                    break;
                case 3:
                    res = tree->upgradeLock(name, id);
                    break;
                default:
                    break;
            }
            cout << (res ? "true" : "false") << "\n";
        }
    }
}


/*
Problem Statement :- Largest Sum Cycle
You are given a complete, balanced M-Ary Tree and must support Q queries. There are 3 kinds of queries. Return true or false depending on whether the query was successful.

Lock(v, id) - Lock vertex v for user - id
Unlock(v, id) - If vertex v is locked by the same id, unlock it.
Upgrade(v, id) - If v is unlocked and has at least one locked vertex in it's subtree and every locked vertex in the subtree of v is locked by id, unlock them and lock v instead.
Further, here are some additional constraints

A vertex cannot be locked if it has any locked ancestors or descendants, by any ID.
When a vertex is upgraded, it's locked descendants are automatically unlocked.
An upgrade operation is not possible if the vertex is already locked or has any locked ancestors
An unlock operation is only possible if the vertex is already locked and locked by the same id
P.S. - The question was very badly stated and not a single constraint was mentioned openly on the problem statement. A lot of these constraints had to be deduced by supplying custom input and observing the expected output. There were no constraints on the size of the variables.

INPUT FORMAT :-
The first line contains the total number of test cases T.
For each test case:
The first line contains N which is the number of vertices in the tree.
The second line contains M which is the max number of children of an M-ary tree.
The third line contains Q which is the number of queries.
The next N lines contain the vertices of the tree.
The next Q lines each contain operation number, vertex and user id. 

OUTPUT FORMAT :
For each test case, we have Q lines each containing
whether the operation can be performed or not.

Sample Input :
2
7
2
5
World
Asia
Africa
India
China
SouthAfrica
Egypt
1 China 9
1 India 9
3 Asia 9
2 India 9
2 Asia 9
3
2
2
World
China
India
3 India 1
1 World 9

Sample Output :
true
true
true
false
true
false
true

Time complexity ->

(1) lock operation -> O(logm(n)) -> log n base m
logic -> we will check all descendents are locked or not 
(in O(1) means constant time) and ancestors are locked or not 
by exploring each ancestor one by one (in logm(n)) time

(2) unlock -> O(logm(n)) -> log n base m
logic -> if given node is locked and locked by same id then 
we will inform all anesctors about its unlocking in logm(n) 
by exploring each ancestor one by one.

(3) upgrade -> O(no of locked descendants * logm(n))
logic -> check one or more than one descendants are locked 
by same Id or not (if 5 descendants are locked then we can 
check in O(5) time)
-- check 0 ancestors are locked or not in O(logm(n)) time
--- unlock all descendants in O(no of locked descendantslogm(n)) time

Space complexity -> O(n)

In upgrade operation we have to lock one node that we want to upgrade -> O(logm(n))
we have to unlock all locked descendant of the given node -> each will take O(logm(n))
total upgrade operation time complexity -> O(1+no of locked descendants)*logm(n) -> O(no of locked descendants)*logm(n).
O(no of locked descendants)*logm(n) this time complexity was given in this question and we can’t optimistic it (and if you have any solution please add that here).

Why did you choose set as data structure for storing descendants ?
--Set is required to store all locked descendents of any node and here we can use unordered_set (or some hashing concept also we can use) to optimise its time complexity but if we use vector than it will increase its time complexity so vector is the worst choose.

Wouldn't storing all the descendants at every parent use too much of memory and exceed the limit in bigger inputs?
--it will not give any memory limit exceed. if 1 descendant is locked than it will inform logm(n) ancestors (at most) about its locking. so if all nodes are locked than it will increase its space complexity up to O(n*logm(n)).

Is this question in any way related to threading?
-- till now this is not related to threading but threading concept we can add anywhere.
*/