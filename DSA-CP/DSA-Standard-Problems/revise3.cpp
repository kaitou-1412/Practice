#include<bits/stdc++.h>
using namespace std;

/**
 * Day 3:
 *  1. Search in Rotated Sorted Array I
 *  2. Search in Rotated Sorted Array II
 *  3. Find minimum in Rotated Sorted Array
 *  4. Find peak element
 *  5. Koko Eating Bananas
 *  6. Kth Missing Positive Number
 *  7. Aggressive Cows
 *  8. Minimize Max Distance to Gas Station
 *  9. Median of 2 sorted arrays
 * 10. Kth element of 2 sorted arrays
 * 11. Matrix Median
**/

int search_in_rotated_sorted_array_I(vector<int> &a, int k) {
    int n = a.size();
    int low = 0, high = n-1;
    while(low<=high) {
        int mid = low + (high-low)/2;
        if(a[mid] == k) return mid;
        if(a[mid]>a[high]) {
            if(a[low]<=k && k<a[mid]) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        } else {
            if(a[mid]<k && k<=a[high]) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
    }
    return -1;
}

bool search_in_rotated_sorted_array_II(vector<int> &a, int k) {
    int n = a.size();
    int low = 0, high = n-1;
    while(low<=high) {
        int mid = low + (high-low)/2;
        if(a[mid] == k) return true;
        if(a[low] == a[mid] && a[mid] == a[high]) {
            low++;
            high--;
            continue;
        }
        if(a[mid]>a[high]) {
            if(a[low]<=k && k<a[mid]) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        } else {
            if(a[mid]<k && k<=a[high]) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
    }
    return false;
}

int find_minimum_in_rotated_sorted_array(vector<int> &a) {
    int n = a.size();
    int low = 0, high = n-1;
    while(low<high) {
        int mid = low + (high-low)/2;
        if(a[mid]>a[high]) {
            low = mid+1;
        } else {
            high = mid;
        }
    }
    return a[low];
}

int find_peak_element_index(vector<int> &a) {
    int n = a.size();
    int low = 0, high = n-1;
    while(low<high) {
        int mid = low + (high-low)/2;
        if(a[mid]>a[mid+1]) {
            high = mid;
        } else {
            low = mid+1;
        }
    }
    return low;
}

int eating_time(vector<int> &a, int k) {
    int n = a.size(), time = 0;
    for(int i=0; i<n; i++) {
        time += (int)ceil((double)a[i]/k);
    }
    return time;
}

int koko_eating_bananas(vector<int> &a, int h) {
    int n = a.size();
    int low = 0, high = *max_element(a.begin(), a.end());
    while(low<high) {
        int mid = low + (high-low)/2;
        if(eating_time(a, mid) > h) {
            low = mid+1;
        } else {
            high = mid;
        }
    }
    return low;
}

int kth_missing_positive_number(vector<int> &a, int k) {
    int n = a.size();
    int low = 0, high = n-1;
    while(low<=high) {
        int mid = low + (high - low)/2;
        if(a[mid] - mid - 1 < k) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return k + high + 1;
}

int placed_cows(vector<int> &a, int d) {
    int n = a.size(), cows = 1, prev_id = 0;
    for(int i=1; i<n; i++) {
        if(a[i] - a[prev_id] >= d) {
            cows++;
            prev_id = i;
        } 
    }
    return cows;
}

int aggressive_cows(vector<int> &a, int k) {
    int n  = a.size();
    sort(a.begin(), a.end());
    int low = 1, high = a[n-1] - a[0];
    while(low<=high) {
        int mid = low + (high - low)/2;
        if(placed_cows(a, mid) >= k) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return high;
}

int placed_stations(vector<int> &a, double d) {
    int n = a.size(), stations = 0;
    for(int i=1; i<n; i++) {
        int stations_in_between = (a[i] - a[i-1])/d;
        if(a[i] - a[i-1] == d*stations_in_between) stations_in_between--;
        stations += stations_in_between;
    }
    return stations;
} 

double gas_station(vector<int> &a, int k) {
    int n  = a.size();
    sort(a.begin(), a.end());
    double low = 0, high = INT_MIN;
    for(int i=1; i<n; i++) high = max(high, (double)(a[i] - a[i-1]));
    while(1e-6<high-low) {
        double mid = low + (high - low)/2;
        if(placed_stations(a, mid) > k) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return high;
}

double median_of_2_sorted_arrays(vector<int> &v, vector<int> &u) {
    int n = v.size(), m = u.size();
    if(n>m) return median_of_2_sorted_arrays(u, v);
    int total_elememts = n+m;
    int total_left_elememts = total_elememts/2;
    int total_right_elements = total_elememts - total_left_elememts;
    int low = 0, high = n;
    while(low<=high) {
        int mid = low + (high - low)/2;
        int l1 = (mid < 1) ? INT_MIN : v[mid-1];
        int l2 = (total_left_elememts - mid < 1) ? INT_MIN : u[total_left_elememts - mid - 1];
        int r1 = (mid >= n) ? INT_MAX : v[mid];
        int r2 = (total_left_elememts - mid >= m) ? INT_MAX : u[total_left_elememts - mid];
        if(l1<=r2 && l2<=r1) {
            if(total_elememts&1) {
                return min(r1, r2);
            } else {
                return (double)(max(l1, l2) + min(r1, r2))/2;
            }
        } else if(l1>r2) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return 0.0;
}

int Kth_element_of_2_sorted_arrays(vector<int> &v, vector<int> &u, int k) {
    int n = v.size(), m = u.size();
    if(n>m) return Kth_element_of_2_sorted_arrays(u, v, k);
    int total_elememts = n+m;
    int total_left_elememts = k-1;
    int total_right_elements = total_elememts - total_left_elememts;
    int low = 0, high = n;
    while(low<=high) {
        int mid = low + (high - low)/2;
        int l1 = (mid < 1) ? INT_MIN : v[mid-1];
        int l2 = (total_left_elememts - mid < 1) ? INT_MIN : u[total_left_elememts - mid - 1];
        int r1 = (mid >= n) ? INT_MAX : v[mid];
        int r2 = (total_left_elememts - mid >= m) ? INT_MAX : u[total_left_elememts - mid];
        if(l1<=r2 && l2<=r1) {
            return min(r1, r2);
        } else if(l1>r2) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return -1;
}

int countLessThanOrEqual(vector<int> &row, int mid) {
    // Using upper_bound to find count efficiently
    return upper_bound(row.begin(), row.end(), mid) - row.begin();
}

int matrix_median(vector<vector<int>> &a) {
    int m = a.size(), n = a[0].size();
    int low = INT_MAX, high = INT_MIN, k = ((m*n)+1)/2;
    for(int i=0; i<m; i++) low = min(low, a[i][0]), high = max(high, a[i][n-1]);
    while(low<high) {
        int mid = low + (high - low)/2;
        int lte_count = 0;
        for(int i=0; i<m; i++) lte_count += countLessThanOrEqual(a[i], mid);
        if(lte_count < k) low = mid + 1;
        else high = mid;
    }
    return low;
}

void solve() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> v(m, vector<int>(n, 0)); 
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) cin >> v[i][j];
    int res = matrix_median(v);
    cout << res << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}