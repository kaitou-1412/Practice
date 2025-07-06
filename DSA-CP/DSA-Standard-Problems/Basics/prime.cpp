// Check Prime Number
#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Checks if a given integer is a prime number.
 *
 * This function determines whether the input integer `n` is a prime number.
 * It uses an optimized approach by first handling small cases and then
 * checking divisibility using numbers of the form 6k ± 1 up to sqrt(n).
 *
 * @param n The integer to check for primality.
 * @return true if `n` is a prime number, false otherwise.
 *
 * @note
 * - Negative numbers, 0, and 1 are not considered prime.
 * - 2 and 3 are considered prime.
 *
 * @complexity
 * Time Complexity: O(sqrt(n)), since it checks divisibility up to the square root of n.
 * Space Complexity: O(1), as it uses a constant amount of extra space.
 */
bool prime(long long int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

void solve() {
    long long int n;
    cin >> n;
    cout << (prime(n) ? "Prime" : "Not Prime") << "\n";
}

int main() {
    long long int t;
    cin >> t;
    while(t--) {
        solve();
    }
}