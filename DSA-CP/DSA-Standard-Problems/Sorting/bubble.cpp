// Bubble Sort Algorithm
#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Sorts an array using the bubble sort algorithm.
 *
 * This function implements the bubble sort algorithm, which repeatedly
 * steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
 * The pass through the list is repeated until the list is sorted.
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
void bubbleSort(int n, vector<int> &arr) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
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
    bubbleSort(n, arr);
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