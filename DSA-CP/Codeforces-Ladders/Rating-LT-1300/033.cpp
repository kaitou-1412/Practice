// A. Supercentral Point
#include<bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};
 
bool right_neighbor(Point a, Point b) {
    if(a.x < b.x && a.y == b.y)
        return true;
    return false;
}
 
bool left_neighbor(Point a, Point b) {
    if(a.x > b.x && a.y == b.y)
        return true;
    return false;
}
 
bool upper_neighbor(Point a, Point b) {
    if(a.x == b.x && a.y < b.y)
        return true;
    return false;
}
 
bool lower_neighbor(Point a, Point b) {
    if(a.x == b.x && a.y > b.y)
        return true;
    return false;
}

void solve() {
    int n;
    cin >> n;
    Point p[n];
    for(int i = 0; i<n; i++)
        cin >> p[i].x >> p[i].y;
    if(n<5) {
        cout << "0\n";
        return;
    }
    int counter = 0;
    int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            if(i == j)
                continue;
            if(flag1 != 1 && right_neighbor(p[i], p[j]))
                flag1 = 1;
            else if(flag2 != 1 && left_neighbor(p[i], p[j]))
                flag2 = 1;
            else if(flag3 != 1 && upper_neighbor(p[i], p[j]))
                flag3 = 1;
            else if(flag4 != 1 && lower_neighbor(p[i], p[j]))
                flag4 = 1;
        }
        if(flag1*flag2*flag3*flag4)
            counter++;
        flag1 = 0;
        flag2 = 0;
        flag3 = 0;
        flag4 = 0;
    }
    cout << counter << "\n";
}

int main() {
    solve();
    return 0;
}
