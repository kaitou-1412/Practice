#include<bits/stdc++.h>
using namespace std;

/**
 * Day 4:
 *  1. Number of substrings that contain exactly k distinct characters
 *  2. Longest Palindromic Substring (without DP)
 *  3. Length of Loop in LL
 *  4. Check if LL is palindrome or not
 *  5. Sort LL
 *  6. Find the intersection point of Y LL
 *  7. Flattening of LL
 *  8. Clone a Linked List with random and next pointer
 *  9. Sort a stack using recursion
 * 10. Print all subsequences/Power Set
 * 11. Count all subsequences with sum K
 * 12. Combination Sum
 * 13. Subset Sum
 * 14. N Queen
 * 15. Expression Add Operators
 * 16. Find xor of numbers from L to R
 * 17. Find the two numbers appearing odd number of times
**/

int countSubStringsLTE(string s, int k) {
    int n = s.size(), left = 0, right = 0, res = 0;
    unordered_map<char, int> mp;
    while(right<n) {
        mp[s[right]]++;
        while(left<=right && mp.size()>k) {
            mp[s[left]]--;
            if(mp[s[left]] == 0) mp.erase(s[left]);
            left++;
        }
        res += (right - left + 1); 
        right++;
    }
    return res;
}

int countSubStrings(string s, int k) {
    int ans = countSubStringsLTE(s, k) - countSubStringsLTE(s, k-1);
    return ans;  
}

string longestPalindrome(string s) {
    string res, subs = "", subsrev = "";
    int n = s.size(), right, max_len = INT_MIN;
    for(int left=0; left<n; left++) {
        right = n-1;
        while(left<=right) {
            if((s[left] == s[right]) && (max_len < (right-left+1))) {
                subs = s.substr(left, right-left+1);
                subsrev = subs;
                reverse(subsrev.begin(), subsrev.end());
                if(subs == subsrev) {
                    res = subs;
                    max_len = right-left+1;
                }
            }
            right--;
        }
    }
    return res;    
}

struct Node {
    int data;
    Node *next, *child, *random;
    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next) {
        this->data = data;
        this->next = next;
    }
};

int lengthOfLoop(Node *head) {
    Node *h = head, *t = head;
    do {
        if(!h || !h->next) return -1;
        h = h->next->next;
        t = t->next;
    } while(h!=t);
    t = head;
    while(h!=t) {
        h = h->next;
        t = t->next;
    }
    Node *firstNode = h;
    int ans = 0;
    do {
        ans++;
        h = h->next;
    } while(h!=firstNode);
    return ans;
}

Node *findMiddle(Node *head) {
    Node *hare = head, *tortoise = head;
    while(hare && hare->next) {
        tortoise = tortoise->next;
        hare = hare->next->next;
    }
    return tortoise;
}

Node* reverseLinkedList(Node *head) {
    Node* tail = head, *tailprev = NULL;
    if(!tail->next) return tail;
    while (tail) {
      Node* temp = tail->next;
      tail->next = tailprev;
      tailprev = tail;
      tail = temp;
    }
    return tailprev;
}

bool isPalindrome(Node *head) {
    if(!head || !head->next) return true;
    Node* middle = findMiddle(head);
    Node* tail = head;
    while(tail->next != middle) tail = tail->next;
    tail->next = NULL;
    Node* reversedMiddle = reverseLinkedList(middle);
    while(head && reversedMiddle && head->data == reversedMiddle->data) {
        head = head->next;
        reversedMiddle = reversedMiddle->next;
    }
    return !(head && reversedMiddle && head->data != reversedMiddle->data);
}

void split(Node *head, Node **first, Node **second) {
    Node *tortoise = head, *hare = head->next;
    while(hare) {
        hare = hare->next;
        if(hare) {
            tortoise = tortoise->next;
            hare = hare->next;
        }
    }
    *first = head;
    *second = tortoise->next;
    tortoise->next = NULL;
}

Node* mergeSorted(Node *first, Node *second) {
    Node *ans = new Node(), *temp = new Node();
    ans = temp;
    while(first && second) {
        if(first->data < second->data) {
            temp->next = first;
            first = first->next;
        } else {
            temp->next = second;
            second = second->next;
        }
        temp = temp->next;
    }
    while(first) {
        temp->next = first; 
        first = first->next;
        temp = temp->next;
    }
    while(second) {
        temp->next = second;
        second = second->next;
        temp = temp->next;
    }
    temp->next = NULL;
    return ans->next;
}

Node* sortList(Node* head) {
    if(!head || !head->next) return head;
    Node *first = NULL, *second = NULL;
    split(head, &first, &second);
    return mergeSorted(sortList(first), sortList(second));
}

Node* findIntersection(Node *firstHead, Node *secondHead) {
    if(!firstHead || !secondHead) return NULL;
    Node *f = firstHead, *s = secondHead;
    while(f != s) {
        f = f->next;
        s = s->next;
        if(f == s) return f;
        if(!f) f = secondHead;
        if(!s) s = firstHead;
    }
    return f;
}

Node* merge(Node *first, Node *second) {
	if(!first) {
		second->next = nullptr;
		return second;
	}
	if(!second) {
		first->next = nullptr;
		return first;
	}
    Node *merged = NULL;
    if (first->data < second->data) {
        merged = first;
        merged->child = merge(first->child, second);
    } else {
        merged = second;
        merged->child = merge(first, second->child);
    }
    merged->next = nullptr;
    return merged;
}

Node *flattenLinkedList(Node *head) {
	if (!head || !head->next) return head; 
	head->next = flattenLinkedList(head->next); 
	head = merge(head, head->next); 
	return head; 
}

Node *cloneLL(Node *head) {
	if(!head) return head;
	Node *temp = head;
	while(temp) {
		Node *newNode = new Node(temp->data);
		newNode->next = temp->next;
		temp->next = newNode;
		temp = temp->next->next;
	}
	Node *curr = head;
	while(curr) {
		if(curr->random) curr->next->random = curr->random->next;
		curr = curr->next->next;
	}
	Node *res = new Node(0);
	curr = head;
	temp = res;
	Node *fast;
	while(curr) {
		fast = curr->next->next;
		temp->next = curr->next;
		curr->next = fast;
		temp = temp->next;
		curr = fast;
	}
	return res->next;
}

void insertAtbottom(stack<int> &s, int temp){
    if(s.empty() || temp>=s.top()){
        s.push(temp);
        return;
    }
    int num=s.top();
    s.pop();
    insertAtbottom(s, temp);
    s.push(num);
}

void sortStack(stack<int> &s){
    if(s.empty()) return;
    int temp=s.top();
    s.pop();
    sortStack(s);
    insertAtbottom(s,temp);
}

void generateSubsequencesHelper(vector<string> &ans, int idx, string s, string res) {
    if(idx == s.size()) {
        ans.push_back(res);
        return;
    }   
    generateSubsequencesHelper(ans, idx+1, s, res + s[idx]);
    generateSubsequencesHelper(ans, idx+1, s, res);
}

vector<string> generateSubsequences(string s) {
    vector<string> ans;
    generateSubsequencesHelper(ans, 0, s, "");
    return ans;
}

vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
    int n = a.size();
    vector<vector<int>> ans;
    int start = 0, end = -1;
    long long currentSum = 0;
    while (start < n) {
        while ((end + 1 < n) && (currentSum + a[end + 1] <= k)) {
            currentSum += a[end + 1];
            ++end;
        }
        if (currentSum == k) {
            vector<int> temp;
            for(int i = start; i <= end; ++i) temp.push_back(a[i]);
            ans.push_back(temp);
        }
        currentSum -= a[start];
        ++start;
    }
    return ans;
}

void combSumHelper(int ind, int b, vector<int> &a, vector<int> &temp, vector<vector<int>> &ans) {
    if (b < 0) return;
    if (b == 0) {
        ans.push_back(temp);
        return;
    }
    for(int i=ind; i<a.size(); i++) {
		if(i>ind && a[i] == a[i-1]) continue;
		temp.push_back(a[i]);
		combSumHelper(i, b-a[i], a, temp, ans);
		temp.pop_back();
	}
}

vector<vector<int>> combSum(vector<int> &a, int b) {
    vector<vector<int>> ans;
    vector<int> temp;
    sort(a.begin(), a.end());
    combSumHelper(0, b, a, temp, ans);
    return ans;
}

void subsetSumHelper(vector<int> &ans, int idx, vector<int> num, int sum) {
    if (idx == num.size()) {
    	ans.push_back(sum);
		return;
    }
    subsetSumHelper(ans, idx+1, num, sum);
    subsetSumHelper(ans, idx+1, num, sum + num[idx]);
}

vector<int> subsetSum(vector<int> &num) {
	vector<int> ans;
    subsetSumHelper(ans, 0, num, 0);
	sort(ans.begin(), ans.end());
    return ans;
}

bool isSafe(int r, int c, vector<string> &board) {
    int n = board.size(), row = r, col = c;
    while(row>=0 && col>=0) {
        if(board[row][col] == 'Q') {
            return false;
        }
        row--;
        col--;
    }
    row = r, col = c;
    while(row<n && col>=0) {
        if(board[row][col] == 'Q') {
            return false;
        }
        row++;
        col--;
    }
    row = r, col = c;
    while(col>=0) {
        if(board[row][col] == 'Q') {
            return false;
        }
        col--;
    }
    return true;
}

void nQueensHelper(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
    if(col == n) {
        ans.push_back(board);
        return;
    }
    for(int row=0; row<n; row++) {
        if (isSafe(row, col, board)) {
            board[row][col] = 'Q';
            nQueensHelper(col + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<int>> nQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i=0; i<n; i++) board[i] = s;
    nQueensHelper(0, board, ans, n);
    vector<vector<int>> res;
    vector<int> v;
    for (int i=0; i<ans.size(); i++) {
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
              v.push_back(ans[i][row][col] == 'Q' ? 1 : 0);
            }
        }
        res.push_back(v);
        v.clear();
    }
    return res;
}

void addOperatorsHelper(string s, int target, int i, const string& path, long eval, long residual, vector<string> &ans) {
    if(i == s.length()) {
        if(eval == target) {
            ans.push_back(path);
            return;
        }
    } 
    string currStr;
    long num = 0;
    // backtracking loop
    for(int j=i; j<s.length(); j++) {
        // handle 0
        if(j>i && s[i]=='0') return;
        currStr += s[j]; 
        num = num*10 + s[j] - '0';
        if(i==0) {
            addOperatorsHelper(s, target, j+1, path + currStr, num, num, ans);
        } else {
            addOperatorsHelper(s, target, j+1, path + "+" + currStr, eval + num, num, ans);
            addOperatorsHelper(s, target, j+1, path + "-" + currStr, eval - num, -num, ans);
            addOperatorsHelper(s, target, j+1, path + "*" + currStr, eval - residual + residual*num , residual*num, ans);
        }
    }   
}

vector<string> addOperators(string s, int target) {
    vector<string> ans;
    addOperatorsHelper(s, target, 0, "", 0, 0, ans);
    return ans;
}

int findXORHelper(int n) {
    if (n%4 == 0) return n;
    if (n%4 == 1) return 1;
    if (n%4 == 2) return n+1;
    return 0;
}

int findXOR(int L, int R){
    return findXORHelper(L-1)^findXORHelper(R);
}

vector<int> twoOddNum(vector<int> arr) {
    int x=0, first=0, second=0, n=arr.size();
    for(int i=0; i<n; i++) x ^= arr[i];
    int rightMostSetBit = x & (~(x - 1));
    for(int i=0; i<n; i++) {
        if(rightMostSetBit & arr[i]) first ^= arr[i];
        else second ^= arr[i];
    }
    if(first>second) return {first, second};
    return {second, first};
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n, 0); 
    for(int i=0; i<n; i++) cin >> v[i];
    vector<int> res = twoOddNum(v);
    for(int r: res) cout << r << " ";
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}