#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct TreeNode {
	string name;
	int lockedBy;
	int threadCount;
	bool isLocked;
	TreeNode* parent;
	vector<TreeNode*> children;
	unordered_set<TreeNode*> lockedDescendants;

	TreeNode(string nm, TreeNode* par) {
		name = nm;
		lockedBy = -1;
		threadCount = 0;
		isLocked = false;
		parent = par;
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
			if(isLocked) par->lockedDescendants.insert(curr);
			else par->lockedDescendants.erase(curr);
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

	bool lock(string name, int id) {
		TreeNode* r = nameTreeNodeMapping[name];
		r->threadCount++;
		if(r->threadCount > 1 || r->isLocked || r->lockedDescendants.size()) return false;
		r->isLocked = true;
		r->lockedBy = id;
		TreeNode* par = r->parent;
		while(par) {
			par->lockedDescendants.insert(r);
			if (par->isLocked) {
				TreeNode* lockedParent = par;
				lockedParent->lockedDescendants.erase(r);
				par = r->parent;
				while(par != lockedParent) {
					par->lockedDescendants.erase(r);
					par = par->parent;
				}
				r->isLocked = false;
				r->lockedBy = -1;
				break;
			}
			par = par->parent;
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
		return true;
	}

	bool upgradeLock(string name, int id) {
		TreeNode* r = nameTreeNodeMapping[name];
		if(r->isLocked || r->lockedDescendants.empty()) return false;
		for(TreeNode* ld: r->lockedDescendants) {
			if(ld->lockedBy != id) return false;
		}
		if(checkLockedAncestors(r)) return false;
		unordered_set<TreeNode*> setOfLockedDescendants = r->lockedDescendants;
		for(TreeNode* ld: setOfLockedDescendants) {
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
}
