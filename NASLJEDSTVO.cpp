#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, a;
    cin >> n >> a;
    n--;
    int b = a / n;
    if (a - b * n) {
        cout << a + b << ' ' << a + b << '\n';
    }
    else {
        cout << a + b - 1 << ' ' << a + b << '\n';
    }
    return 0;
}