#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, a = 0, b = 1, c = 1;
    cin >> n;
    for (int i = 0; i < 1001; i++) {
        if (a <= n && n < b)
            break;
        a = b; b += (c++);
    }
    int result1 = c - 1, result2 = 1;
    for (int i = 0; i < n - a; i++)
        result1--, result2++;
    cout << result1 << " " << result2;
    return 0;
}
