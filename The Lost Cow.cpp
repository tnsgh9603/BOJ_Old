#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int x, y, cnt = 0;
    cin >> x >> y;
    for (int i = 1, t = 1, cur = x; ; t++, i <<= 1) {
        while (cur != x + (t & 1 ? i : -i)) {
            if (cur == y) {
                cout << cnt << '\n';
                return 0;
            }
            cnt++;
            t & 1 ? cur++ : cur--;
        }
    }
    return 0;
}