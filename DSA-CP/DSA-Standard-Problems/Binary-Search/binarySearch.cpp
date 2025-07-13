// Binary Search Algorithm
#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Performs binary search on a sorted array.
 *
 * This function implements the binary search algorithm, which finds the position of a target value
 * within a sorted array. It repeatedly divides the search interval in half and compares the target
 * value to the middle element.
 *
 * @param arr The sorted array to search.
 * @param target The value to search for.
 * @return The index of the target value if found; -1 otherwise.
 * 
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int binarySearch(const vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target) low = mid + 1;
        else if (arr[mid] == target) return mid;
        else high = mid - 1;
    }
    return -1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int target;
    cin >> target;
    sort(arr.begin(), arr.end()); // Ensure the array is sorted
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
    int result = binarySearch(arr, target);
    if (result != -1) {
        cout << "Element " << target << " found at index: " << result << "\n";
    } else {
        cout << "Element " << target << " not found in the array.\n";
    }
}

int main() {
    long long int t;
    cin >> t;
    while(t--) {
        solve();
    }
}