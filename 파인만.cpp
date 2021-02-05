#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main() {
    fastio;
    int n;
    while (cin >> n && n) {
        cout << n * (n + 1) * (2 * n + 1) / 6 << '\n';
    }
    return 0;
}