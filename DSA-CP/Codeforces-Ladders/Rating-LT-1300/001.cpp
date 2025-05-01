// A. Young Physicist
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, x, y, z, tx = 0, ty = 0, tz = 0;
    cin >> n;
    while(n--)
    {
        cin >> x >> y >> z;
        tx += x;
        ty += y;
        tz += z;
    }
    if(tx == 0 && ty == 0 && tz == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}