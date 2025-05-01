// Josephus Problem II
#include<bits/stdc++.h>
using namespace std;

// My Solution
// void solve() {
//     int n, k;
//     cin >> n >> k;
//     if(n == 1) {
//         cout << "1";
//         return;
//     }
//     set<int> s;
//     for(int i=1; i<=n; i++) {
//         s.insert(i);
//     }
//     auto it = next(s.begin(), k%n);
//     for(int i=0; i<n; i++) {
//         cout << *it << " ";
//         int d = distance(it, s.end());
//         int sz = s.size() - 1;
//         int skips = k, skips_end = d-1;
//         if(sz == 1) {
//             s.erase(it);
//             cout << *s.begin() << " ";
//             break;
//         }
//         if(skips < skips_end) {
//             auto itnext = next(it, skips+1);
//             s.erase(it);
//             it = itnext;
//         } else {
//             int new_skips = skips - skips_end;
//             int actual_skips = new_skips%sz;
//             auto itnext = next(s.begin(), actual_skips);
//             s.erase(it);
//             it = itnext;
//         }
//     }
// }

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

void solve() {
    int n, k;
    cin >> n >> k;
    //using policy based data structure for ordered set
	ordered_set<int> oset;
	
	//inserting values in the set
	for(int i=1;i<=n;i++)oset.insert(i);
	
	//setting initial position
	int pos=k%n;
	
	//printing values until set is not empty
	while(!oset.empty()){
		
		//finding value at pos'th position
		int val = *oset.find_by_order(pos);
		
		//deleting this value
		oset.erase(val);
		
		//printing the value
		cout<<val<<' ';
		
		//finding next position
		if(!oset.empty()){
			pos=(pos+k)%oset.size();
		}
	}
}
            

 
int main() {
    // int t;
    // cin >> t;
    // while(t--) solve();
    ios_base::sync_with_stdio(false);
    solve();
}