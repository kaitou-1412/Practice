#include<bits/stdc++.h>
using namespace std;

/**
 * Day 2:
 *  1. Longest subarray with sum K (Positives + Negatives)
 *  2. Sort an array of 0's 1's and 2's
 *  3. Majority Element (>n/2 times)
 *  4. Majority Elements (>n/3 times)
 *  5. Kadane's Algorithm, maximum subarray sum
 *  6. 2Sum Problem
 *  7. 3Sum Problem
 *  8. 4Sum Problem
 *  9. Next Permutation
 * 10. Rotate Matrix by 90 degrees
 * 11. Print the matrix in spiral manner
 * 12. Count subarrays with given sum
 * 13. Merge Overlapping Subintervals
 * 14. Maximum Product Subarray
**/ 

int longest_subarray_with_sum_k(vector<int> &a, int k) {
    int n = a.size(), res = INT_MIN, sum = 0;
    unordered_map<int, int> prefix_sum;
    prefix_sum[0] = -1;
    for(int i=0; i<n; i++) {
        sum += a[i];
        if(prefix_sum.find(sum - k) != prefix_sum.end()) {
            res = max(res, i - prefix_sum[sum - k]);
        }
        if(prefix_sum.find(sum) == prefix_sum.end()) {
            prefix_sum[sum] = i;
        }
    }
    return res;
}

void sort_array_012(vector<int> &a) {
    int n = a.size();
    int low = 0, mid = 0, high = n-1;
    while(mid<=high) {
        if(a[mid] == 0) {
            swap(a[low], a[mid]);
            low++;
            mid++;
        } else if(a[mid] == 1) {
            mid++;
        } else {
            swap(a[high], a[mid]);
            high--;    
        }
    }   
}

int majority_element_n_by_2(vector<int> &a) {
    int n = a.size(), res, count = 0;
    for(int i=0; i<n; i++) { 
        if(count == 0) {
            res = a[i];
            count++;
        } else if(res == a[i]) {
            count++;
        } else {
            count--;
        }
    }
    count = 0;
    for(int i=0; i<n; i++) if(a[i] == res) count++;
    if(count>n/2) return res;
    return -1;
}

pair<int, int> majority_element_n_by_3(vector<int> &a) {
    int n = a.size(), res1 = INT_MIN, res2 = INT_MIN, count1 = 0, count2 = 0;
    for(int i=0; i<n; i++) { 
        if(count1 == 0 && res2 != a[i]) {
            res1 = a[i];
            count1++;
        } else if(count2 == 0 && res1 != a[i]) {
            res2 = a[i];
            count2++;
        } else if(res1 == a[i]) {
            count1++;
        } else if(res2 == a[i]) {
            count2++;
        } else {
            count1--;
            count2--;
        }
    }
    count1 = 0, count2 = 0;
    for(int i=0; i<n; i++) {
        if(a[i] == res1) count1++;
        if(a[i] == res2) count2++;
    }
    if(count1<=n/3) res1 = -1; 
    if(count2<=n/3) res2 = -1; 
    return {res1, res2};
}

int maximum_subarray_sum(vector<int> &a) {
    int n = a.size(), res = INT_MIN, sum = 0, start = 0, low = -1, high = -1;
    for(int i=0; i<n; i++) {
        if(sum == 0) start = i;
        sum += a[i];
        if(res<sum) {
            low = start;
            high = i;
            res = sum;
        }
        if(sum<0) {
            sum = 0;
        }
    }
    cout << "Subarray: ";
    for(int i=low; i<=high; i++) cout << a[i] << " ";
    cout << "\n";
    return res;
} 

vector<int> two_sum(vector<int> &a, int target) {
    int n = a.size();
    vector<int> res;
    sort(a.begin(), a.end());
    int i = 0, j = n-1;
    while(i<j) {
        if(a[i] + a[j] == target) {
            res.push_back(a[i]);
            res.push_back(a[j]);
            break;
        } else if(a[i] + a[j] < target) {
            i++;
        } else {
            j--;
        }
    }
    return res; 
}

vector<int> three_sum(vector<int> &a, int target) {
    int n = a.size();
    vector<int> res;
    sort(a.begin(), a.end());
    for(int i=0; i<=n-3; i++) {
        if(i>0 && a[i] == a[i-1]) continue;
        int j = i+1, k = n-1, found = 0;
        while(j<k) {
            if(a[i] + a[j] + a[k] == target) {
                res.push_back(a[i]);
                res.push_back(a[j]);
                res.push_back(a[k]);
                found = 1;
                break;
            } else if(a[i] + a[j] + a[k] < target) {
                j++;
            } else {
                k--;
            }
        }
        if(found == 1) break;
    }
    return res; 
}

vector<int> four_sum(vector<int> &a, int target) {
    int n = a.size();
    vector<int> res;
    sort(a.begin(), a.end());
    for(int i=0; i<=n-4; i++) {
        if(i>0 && a[i] == a[i-1]) continue;
        int found1 = 0;
        for(int j=i+1; j<=n-3; j++) {
            if(j>i+1 && a[j] == a[j-1]) continue;
            int k = j+1, l = n-1, found2 = 0;
            while(k<l) {
                if(a[i] + a[j] + a[k] + a[l] == target) {
                    res.push_back(a[i]);
                    res.push_back(a[j]);
                    res.push_back(a[k]);
                    res.push_back(a[l]);
                    found1 = 1;
                    found2 = 1;
                    break;
                } else if(a[i] + a[j] + a[k] + a[l] < target) {
                    k++;
                } else {
                    l--;
                }
            }
            if(found2 == 1) break;
        }
        if(found1 == 1) break;
    }
    return res; 
}

void next_permutation(vector<int> &a) {
    int n = a.size();
    int k = -1;
    for(int i=n-2; i>=0; i--) {
        if(a[i]<a[i+1]) {
            k = i;
            break; 
        }
    }
    if(k == -1) {
        reverse(a.begin(), a.end());
        return;
    }
    for(int i=n-1; i>k; i--) {
        if(a[i]>a[k]) {
            swap(a[k], a[i]);
            break;
        }
    }
    reverse(a.begin() + k + 1, a.end());
}

void rotate_by_90_degrees(vector<vector<int>> &a) {
    int n = a.size();
    // Transpose matrix
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            swap(a[i][j], a[j][i]);
        }
    }
    // Reverse all rows
    for(int i=0; i<n; i++) {
        reverse(a[i].begin(), a[i].end());
    }
}

vector<int> spiral(vector<vector<int>> &a) {
    int n = a.size();
    int left = 0, top = 0, bottom = n-1, right = n-1;
    vector<int> res;
    while(top<=bottom && left<=right) {
        for(int j=left; j<=right; j++) {
            res.push_back(a[top][j]);
        }
        top++;
        if(top>bottom) break;
        for(int i=top; i<=bottom; i++) {
            res.push_back(a[i][right]);
        }
        right--;
        if(left>right) break;
        for(int j=right; j>=left; j--) {
            res.push_back(a[bottom][j]);
        }
        bottom--;
        if(top>bottom) break;
        for(int i=bottom; i>=top; i--) {
            res.push_back(a[i][left]);
        }
        left++;
        if(left>right) break;
    }
    return res;
}

int count_subarray_sum_k(vector<int> &a, int k) {
    int n = a.size(), res = 0, sum = 0;
    unordered_map<int, int> prefix_sum;
    prefix_sum[0] = 1;
    for(int i=0; i<n; i++) {
        sum += a[i];
        res += prefix_sum[sum-k];
        prefix_sum[sum]++;
    }
    return res;
} 

bool compare_intervals(const vector<int> &a, const vector<int> &b) {
    if(a[0] == b[0]) return a[1] <= b[1];
    return a[0] < b[0];
}

vector<vector<int>> merge_intervals(vector<vector<int>> &intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), compare_intervals);
    vector<vector<int>> res;
    int x1 = intervals[0][0], y1 = intervals[0][1], x2, y2;
    for(int i=1; i<n; i++) {
        x2 = intervals[i][0];
        y2 = intervals[i][1];
        if(y1 < x2) {
            res.push_back({x1, y1});
            x1 = x2;
            y1 = y2;
        } else {
            y1 = max(y1, y2);
        }
    }
    res.push_back({x1, y1});
    return res;
}

int maximum_product_subarray(vector<int> &a) {
    int n = a.size();
    int min_neg = a[0], max_pos = a[0], res = a[0];
    for(int i=1; i<n; i++) {
        if(a[i]<0) swap(min_neg, max_pos);
        max_pos = max(a[i], max_pos*a[i]);
        min_neg = min(a[i], min_neg*a[i]);
        res = max(res, max_pos);
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n); 
    for(int i=0; i<n; i++) cin >> v[i];
    int res = maximum_product_subarray(v);
    cout << res << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}