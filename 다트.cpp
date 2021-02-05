#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a = 0, b = 0;
        for (int j = 0; j < 6; ++j) {
            double x, y;
            cin >> x >> y;
            double d = sqrt(x * x + y * y);
            int z = (int)(18 - d) / 3 * 20;
            if (z < 0) {
                z = 0;
            }
            if (z > 100) {
                z = 100;
            }
            if (j < 3) {
                a += z;
            }
            else {
                b += z;
            }
        }
        printf("SCORE: %d to %d, %s.\n", a, b, a > b ? "PLAYER 1 WINS" : a == b ? "TIE" : "PLAYER 2 WINS");
    }
    return 0;
}
