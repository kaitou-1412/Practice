// Greatest Common Divisor
#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Computes the greatest common divisor (GCD) of two integers using the Euclidean algorithm.
 *
 * This function recursively calculates the GCD of two integers n and m.
 * If n is less than m, their values are swapped to ensure n >= m.
 * The recursion continues until m becomes zero, at which point n is the GCD.
 *
 * @param n First integer.
 * @param m Second integer.
 * @return int The greatest common divisor of n and m.
 *
 * @note The function assumes n and m are non-negative integers.
 *
 * @complexity
 * Time Complexity: O(log(min(n, m))) — Each recursive call reduces the problem size significantly.
 * Space Complexity: O(log(min(n, m))) — Due to the recursion stack.
 */
int gcd(long long int n, long long int m) {
    if (n < m) return gcd(m, n);
    if (m == 0) return n;
    return gcd(m, n % m);
}

void solve() {
    long long int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << "\n";
}

int main() {
    long long int t;
    cin >> t;
    while(t--) {
        solve();
    }
}