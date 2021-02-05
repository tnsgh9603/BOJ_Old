#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int t, n;
    double xmax, xmin, ymax, ymin, x, y, area, perimeter;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n >> xmax >> ymax;
        xmin = xmax;
        ymin = ymax;
        for (int j = 1; j < n; j++) {
            cin >> x >> y;
            xmax = xmax < x ? x : xmax;
            xmin = xmin < x ? xmin : x;
            ymax = ymax < y ? y : ymax;
            ymin = ymin < y ? ymin : y;
        }
        area = abs(xmax - xmin) * abs(ymax - ymin);
        perimeter = 2 * (abs(xmax - xmin) + abs(ymax - ymin));
        printf("Case %d: Area %.10lf, Perimeter %.10lf\n", i, area, perimeter);
    }
    return 0;
}