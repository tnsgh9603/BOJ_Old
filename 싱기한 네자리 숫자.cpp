#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    for (int i = 1000; i < 10000; i++) {
        int t1 = 0, t2 = 0, t3 = 0, n;
        n = i;
        while (n) {
            t1 += n % 10, n /= 10;
        }
        n = i;
        while (n) {
            t2 += n % 12, n /= 12;
        }
        n = i;
        while (n) {
            t3 += n % 16, n /= 16;
        }
        if (t1 == t2 && t2 == t3) {
            cout << i << '\n';
        }
    }
    return 0;
}
