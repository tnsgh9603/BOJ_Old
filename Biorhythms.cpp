#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int a, b, c, d, i, j = 0;
    while (cin >> a >> b >> c >> d && a != -1 && ++j) {
        a = (a + 368 - d) % 23;
        b = (b + 392 - d) % 28;
        c = (c + 396 - d) % 33;
        vector<int> v(25000);
        for (i = b; i < 25000; i += 28) {
            v[i]++;
        }
        for (i = c; i < 25000; i += 33) {
            v[i]++;
        }
        for (i = a ? a : 23; i < 25000 && v[i] != 2; i += 23);
        cout << "Case " << j << ": the next triple peak occurs in " << i << " days.\n";
    }
    return 0;
}