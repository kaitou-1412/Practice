// Insertion Sort Algorithm
#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Sorts an array using the insertion sort algorithm.
 *
 * This function implements the insertion sort algorithm, which builds a sorted array one element at a time.
 * It takes each element from the input and finds its correct position in the already sorted part of the array.
 *
 * @param n The number of elements in the array.
 * @param arr The array to be sorted.
 * 
 * @note The function modifies the input array in place.
 * 
 * @complexity
 * Time Complexity: O(n^2) — The algorithm consists of two nested loops.
 * Space Complexity: O(1) — The sorting is done in place, requiring no additional space.
 */
void insertionSort(int n, vector<int> &arr) {
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Before Sorting:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
    insertionSort(n, arr);
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