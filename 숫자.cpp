#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    long long n, m;
    cin >> n >> m;
    if (n > m) {
        long long temp = n;
        n = m;
        m = temp;
    }
    if (n != m) {
        cout << m - n - 1 << '\n';
        for (long long i = n + 1; i < m; i++) {
            cout << i << ' ';
        }
    }
    else {
        cout << 0 << '\n';
    }
    return 0;
}
