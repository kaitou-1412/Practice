#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// struct TreeNode {
// 	string name;
// 	int lockedBy;
// 	bool isLocked;
// 	TreeNode* parent;
// 	vector<TreeNode*> children;
// 	unordered_set<TreeNode*> lockedDescendants;

// 	TreeNode(string nm, TreeNode* par) {
// 		name = nm;
// 		lockedBy = -1;
// 		isLocked = false;
// 		parent = par;
// 	}

// 	void addChild(vector<string> &vertices) {
// 		for(string &nm: vertices) {
// 			children.push_back(new TreeNode(nm, this));
// 		}
// 	} 
// };

// struct MAryTree {
// 	TreeNode* root;
// 	unordered_map<string, TreeNode*> nameTreeNodeMapping;

// 	MAryTree(string name) {
// 		root = new TreeNode(name, nullptr);
// 	}

// 	void makeMAryTree(vector<string> &vertices, int m) {
// 		queue<TreeNode*> q;
// 		int startIndex = 1, index, n = vertices.size();
// 		q.push(root);
// 		while(!q.empty()) {
// 			TreeNode* r = q.front();
// 			q.pop();
// 			nameTreeNodeMapping[r->name] = r;
// 			vector<string> children;
// 			for(index=startIndex; index < min(n, startIndex+m); index++) {
// 				children.push_back(vertices[index]);
// 			}
// 			r->addChild(children);
// 			for(TreeNode* child: r->children) {
// 				q.push(child);
// 			}
// 			startIndex = index;
// 		}
// 	}

// 	void informAncestors(TreeNode* curr, bool isLocked) {
// 		TreeNode* par = curr->parent;
// 		while(par) {
// 			if(isLocked) par->lockedDescendants.insert(curr);
// 			else par->lockedDescendants.erase(curr);
// 			par = par->parent;
// 		}
// 	}

// 	bool checkLockedAncestors(TreeNode* curr) {
// 		TreeNode* par = curr->parent;
// 		while(par) {
// 			if(par->isLocked) return true;
// 			par = par->parent;
// 		}
// 		return false;
// 	}

// 	bool lock(string name, int id) {
// 		TreeNode* r = nameTreeNodeMapping[name];
// 		if(r->isLocked || r->lockedDescendants.size()) return false;
// 		if(checkLockedAncestors(r)) return false;
// 		informAncestors(r, true);
// 		r->isLocked = true;
// 		r->lockedBy = id;
// 		return true;
// 	}

// 	bool unlock(string name, int id) {
// 		TreeNode* r = nameTreeNodeMapping[name];
// 		if(!r->isLocked || r->lockedBy != id) return false;
// 		informAncestors(r, false);
// 		r->isLocked = false;
// 		r->lockedBy = -1;
// 		return true;
// 	}

// 	bool upgradeLock(string name, int id) {
// 		TreeNode* r = nameTreeNodeMapping[name];
// 		if(r->isLocked || r->lockedDescendants.empty()) return false;
// 		for(TreeNode* ld: r->lockedDescendants) {
// 			if(ld->lockedBy != id) return false;
// 		}
// 		if(checkLockedAncestors(r)) return false;
// 		unordered_set<TreeNode*> setOfLockedDescendants = r->lockedDescendants;
// 		for(TreeNode* ld: setOfLockedDescendants) {
// 			unlock(ld->name, id);
// 		}
// 		lock(name, id);
// 		return true;
// 	}
// };

struct TreeNode {
	string name;
	int lockedBy;
	bool isLocked;
	int lockedDescendantCount;
	TreeNode* parent;
	vector<TreeNode*> children;
	int threadCount;

	TreeNode(string nm, TreeNode* par) {
		name = nm;
		lockedBy = -1;
		isLocked = false;
		lockedDescendantCount = 0;
		parent = par;
		threadCount = 0;
	}

	void addChild(vector<string> &vertices) {
		for(string &nm: vertices) {
			children.push_back(new TreeNode(nm, this));
		}
	} 
};

struct MAryTree {
	TreeNode* root;
	unordered_map<string, TreeNode*> nameTreeNodeMapping;
	unordered_set<TreeNode*> lockedNodes;

	MAryTree(string name) {
		root = new TreeNode(name, nullptr);
	}

	void makeMAryTree(vector<string> &vertices, int m) {
		queue<TreeNode*> q;
		int startIndex = 1, index, n = vertices.size();
		q.push(root);
		while(!q.empty()) {
			TreeNode* r = q.front();
			q.pop();
			nameTreeNodeMapping[r->name] = r;
			vector<string> children;
			for(index=startIndex; index < min(n, startIndex+m); index++) {
				children.push_back(vertices[index]);
			}
			r->addChild(children);
			for(TreeNode* child: r->children) {
				q.push(child);
			}
			startIndex = index;
		}
	}

	void informAncestors(TreeNode* curr, bool isLocked) {
		TreeNode* par = curr->parent;
		while(par) {
			if(isLocked) par->lockedDescendantCount++;
			else par->lockedDescendantCount--;
			par = par->parent;
		}
	}

	bool checkLockedAncestors(TreeNode* curr) {
		TreeNode* par = curr->parent;
		while(par) {
			if(par->isLocked) return true;
			par = par->parent;
		}
		return false;
	}

	// bool lock(string name, int id) {
	// 	TreeNode* r = nameTreeNodeMapping[name];
	// 	r->threadCount++;
	// 	if(r->threadCount > 1 || r->isLocked || r->lockedDescendants.size()) return false;
	// 	r->isLocked = true;
	// 	r->lockedBy = id;
	// 	TreeNode* par = r->parent;
	// 	while(par) {
	// 		par->lockedDescendants.insert(r);
	// 		if (par->isLocked) {
	// 			TreeNode* lockedParent = par;
	// 			lockedParent->lockedDescendants.erase(r);
	// 			par = r->parent;
	// 			while(par != lockedParent) {
	// 				par->lockedDescendants.erase(r);
	// 				par = par->parent;
	// 			}
	// 			r->isLocked = false;
	// 			r->lockedBy = -1;
	// 			break;
	// 		}
	// 		par = par->parent;
	// 	}
	// 	r->threadCount--;
	// 	return r->isLocked;
	// }

	bool lock(string name, int id) {
		TreeNode* r = nameTreeNodeMapping[name];
		r->threadCount++;
		if(r->threadCount > 1 || r->isLocked || r->lockedDescendantCount > 0) return false;
		r->isLocked = true;
		r->lockedBy = id;
		TreeNode* par = r->parent;
		while(par) {
			par->lockedDescendantCount++;
			if (par->isLocked) {
				TreeNode* lockedParent = par;
				lockedParent->lockedDescendantCount--;
				par = r->parent;
				while(par != lockedParent) {
					par->lockedDescendantCount--;
					par = par->parent;
				}
				r->isLocked = false;
				r->lockedBy = -1;
				break;
			}
			par = par->parent;
		}
		if (r->isLocked) {
			lockedNodes.insert(r);
		}
		r->threadCount--;
		return r->isLocked;
	}

	bool unlock(string name, int id) {
		TreeNode* r = nameTreeNodeMapping[name];
		if(!r->isLocked || r->lockedBy != id) return false;
		informAncestors(r, false);
		r->isLocked = false;
		r->lockedBy = -1;
		lockedNodes.erase(r);
		return true;
	}

	bool upgradeLock(string name, int id) {
		TreeNode* r = nameTreeNodeMapping[name];
		if(r->isLocked || r->lockedDescendantCount == 0) return false;
		vector<TreeNode*> lockedDescendants;
		for(TreeNode* ld: lockedNodes) {
			TreeNode* par = ld->parent;
			while(par) {
				if(par == r) {
					if(ld->lockedBy != id) return false;
					lockedDescendants.push_back(ld);
					break;
				}
				par = par->parent;
			}
		}
		if(checkLockedAncestors(r)) return false;
		for(TreeNode* ld: lockedDescendants) {
			unlock(ld->name, id);
		}
		lock(name, id);
		return true;
	}
};

void solve() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<string> vertices(n);
	for(int i=0; i<n; i++) cin >> vertices[i];
	MAryTree* tree = new MAryTree(vertices[0]);
	tree->makeMAryTree(vertices, m);
	while(q--) {
		bool res = false;
		int opType, uid;
		string name;
		cin >> opType >> name >> uid;
		switch(opType) {
			case 1:
				res = tree->lock(name, uid);
				break;
			case 2:
				res = tree->unlock(name, uid);
				break;
			case 3:
				res = tree->upgradeLock(name, uid);
				break;
			default:
				break;
		}
		cout << (res ? "true" : "false") << "\n";
	}										
}

int main() {
	int t;
	cin >> t;
	while(t--) solve();
    return 0;									
}


/*
Problem Statement :- Tree of Space
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

Space complexity -> O((n / m) * logm(n))

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