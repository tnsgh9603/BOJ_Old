#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, x;
    long s = 0, s2 = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        s += x;
        s2 += x * x;
    }
    cout << (s * s - s2) / 2;
    return 0;
}
