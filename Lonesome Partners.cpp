#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
struct Point { 
    int x, y;
};
int main() {
    fastio;
    int n;
    cin >> n;
    vector<Point> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
    }
    int mx = 0, a, b;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++) {
            int t = (v[i].x - v[j].x) * (v[i].x - v[j].x) + (v[i].y - v[j].y) * (v[i].y - v[j].y);
            if (mx < t) {
                mx = t;
                a = i + 1, b = j + 1;
            }
        }
    }
    cout << a << ' ' << b;
    return 0;
}