#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int p[4], x, y, r, ret = 0;
    for (int i = 0; i < 4; i++) {
        cin >> p[i];
    }
    cin >> x >> y >> r;
    for (int i = 0; i < 4; i++) {
        if (p[i] == x) {
            ret = i + 1;
        }
    }
    cout << ret;
    return 0;
}