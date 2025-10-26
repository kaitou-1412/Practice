#include<bits/stdc++.h>
using namespace std;

/**
 * Day 1:
 * 1. GCD
 * 2. Check Prime
 * 3. Reverse a list
 * 4. Selection Sort
 * 5. Insertion Sort
 * 6. Bubble Sort
 * 7. Merge Sort
 * 8. Quick Sort
 * 9. Binary Search
**/ 

int gcd(int n, int m) {
    if(n<m) return gcd(m, n);
    if(m == 0) return n;
    return gcd(m, n%m);
}

bool check_prime(int n) {
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    for(int i=5; i*i<=n; i+=6) {
        if(n%i == 0 || n%(i+2) == 0) {
            return false;
        }
    }
    return true;
}

void reverse_list(vector<int> &v) {
    int n = v.size();
    for(int i=0; i<n/2; i++) swap(v[i], v[n-1-i]);
}

void selection_sort(vector<int> &v) {
    int n = v.size();
    for(int i=0; i<n; i++) {
        int selected_index = i;
        for(int j=i+1; j<n; j++) {
            if(v[j]<v[selected_index]) {
                selected_index = j;
            }
        }
        swap(v[i], v[selected_index]);
    }
}

void insertion_sort(vector<int> &v) {
    int n = v.size();
    for(int i=0; i<n; i++) {
        int j=i;
        while(j>0 && v[j-1]>v[j]) {
            swap(v[j-1], v[j]);
            j--;
        }
    }
}

void bubble_sort(vector<int> &v) {
    int n = v.size();
    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<i; j++) {
            if(v[j]>v[j+1]) {
                swap(v[j], v[j+1]);
            }
        }
    }
}

void merge(vector<int> &v, int low, int mid, int high) {
    vector<int> temp;
    int i = low, j = mid+1;
    while(i<=mid && j<=high) {
        if(v[i]<=v[j]) {
            temp.push_back(v[i]);
            i++;
        } else {
            temp.push_back(v[j]);
            j++;
        }
    }
    while(i<=mid) {
        temp.push_back(v[i]);
        i++;
    }
    while(j<=high) {
        temp.push_back(v[j]);
        j++;
    }
    for(int i=low; i<=high; i++) {
        v[i] = temp[i-low];
    }
}

void merge_sort(vector<int> &v, int low, int high) {
    if(low>=high) return;
    int mid = low + (high - low)/2;
    merge_sort(v, low, mid);
    merge_sort(v, mid+1, high);
    merge(v, low, mid, high);
}

int partition(vector<int> &v, int low, int high) {
    int pivot = v[high], i = low;
    for(int j=low; j<high; j++) {
        if(v[j]<=pivot) {
            swap(v[i], v[j]);
            i++;
        }
    }
    swap(v[i], v[high]);
    return i;
}

void quick_sort(vector<int> &v, int low, int high) {
    if(low>=high) return;
    int partition_index = partition(v, low, high);
    quick_sort(v, low, partition_index-1);
    quick_sort(v, partition_index+1, high);
}

int binary_search(vector<int> &v, int target) {
    int n = v.size();
    int low = 0, high = n-1, mid;
    while(low<=high) {
        mid = low + (high - low)/2;
        if(v[mid]<target) {
            low = mid + 1;
        } else if(v[mid]>target) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

void solve() {
    int n, target;
    cin >> n >> target;
    vector<int> v(n); 
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    cout << "Sorted Array: ";
    for(int num: v) cout << num << " ";
    cout << "\n";
    int index = binary_search(v, target);
    if(index == -1) {
        cout << "Target " << target << " not found\n";
    } else {
        cout << "Target index: " << index << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}