#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int INF = int(1e9);
int main() {
    fastio;
    int x, y; 
    cin >> x >> y;
    int nx, ny; nx = ny = INF;
    int n; 
    cin >> n;
    while (n--) {
        int a, b; cin >> a >> b;
        if (abs(a - x) + abs(b - y) <= abs(nx - x) + abs(ny - y)) {
            nx = a, ny = b;
        }
    }
    cout << nx << ' ' << ny << '\n';
    return 0;
}