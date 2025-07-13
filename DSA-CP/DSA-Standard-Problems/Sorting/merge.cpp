// Merge Sort Algorithm
#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Sorts an array using the merge sort algorithm.
 *
 * This function implements the merge sort algorithm, which is a divide-and-conquer algorithm.
 * It divides the array into two halves, sorts each half recursively, and then merges the sorted halves.
 *
 * @param n The number of elements in the array.
 * @param arr The array to be sorted.
 * 
 * @note The function modifies the input array in place.
 * @note The merge function is used to combine two sorted arrays into one sorted array.
 * @param left The left half of the array.
 * @param right The right half of the array.
 * @param merged The array to store the merged result.
 * 
 * @note The merge function assumes that both left and right arrays are already sorted.
 * 
 * @complexity
 * Time Complexity: O(n log n) — The algorithm divides the array into halves and merges them.
 * Space Complexity: O(n) — Additional space is used for merging.
 */
void merge(const vector<int> &left, const vector<int> &right, vector<int> &merged) {
    int i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            merged[k++] = left[i++];
        } else {
            merged[k++] = right[j++];
        }
    }
    while (i < left.size()) merged[k++] = left[i++];
    while (j < right.size()) merged[k++] = right[j++];
}

void mergeSort(int n, vector<int> &arr) {
    if (n < 2) return;  // Base case: if the array has 0 or 1 elements, it's already sorted

    int mid = n / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    mergeSort(left.size(), left);
    mergeSort(right.size(), right);

    merge(left, right, arr);
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Before Sorting:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
    mergeSort(n, arr);
    cout << "After Sorting:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    long long int t;
    cin >> t;
    while(t--) {
        solve();
    }
}