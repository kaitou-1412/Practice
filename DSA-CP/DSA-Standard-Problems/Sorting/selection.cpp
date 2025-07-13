// Selection Sort Algorithm
#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Sorts an array using the selection sort algorithm.
 *
 * This function implements the selection sort algorithm, which repeatedly
 * selects the minimum element from the unsorted portion of the array
 * and swaps it with the first unsorted element.
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
void selectionSort(int n, vector<int> &arr) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
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
    selectionSort(n, arr);
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