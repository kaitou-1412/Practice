// Quick Sort Algorithm
#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Sorts an array using the quick sort algorithm.
 *
 * This function implements the quick sort algorithm, which is a divide-and-conquer algorithm.
 * It selects a pivot element and partitions the array into two halves, sorting each half recursively.
 *
 * @param low The starting index of the array.
 * @param high The ending index of the array.
 * @param arr The array to be sorted.
 * 
 * @note The function modifies the input array in place.
 * 
 * @complexity
 * Time Complexity: O(n log n) on average; O(n^2) in the worst case (when the pivot is always the smallest or largest element).
 * Space Complexity: O(log n) — Additional space used for recursion stack.
 */

int partition(int low, int high, vector<int> &arr) {
    int pivot = arr[high], i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void quickSort(int low, int high, vector<int> &arr) {
    if (low >= high) return;
    int pivotIndex = partition(low, high, arr);
    quickSort(low, pivotIndex - 1, arr);
    quickSort(pivotIndex + 1, high, arr);
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Before Sorting:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
    quickSort(0, n - 1, arr);
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