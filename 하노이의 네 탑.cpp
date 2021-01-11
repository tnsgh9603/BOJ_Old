#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
long long sol(int n, int r) {
    if (n == 1) {
        return 1;
    }
    if (r == 3) {
        return pow(2, n) - 1;
    }
    long long k = n - round(sqrt(2 * n + 1)) + 1;
    return 2 * sol(k, r) + sol(n - k, r - 1);
}
int main() {
    int test = 1, n;
    while (cin >> n) {
        cout << "Case " << test++ << ": " << sol(n, 4) << "\n";
    }
    return 0;
}