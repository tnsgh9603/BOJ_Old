#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main() {
    fastio;
    int n;
    cin >> n;
    if (n % 2) {
        cout << string(n, '*') << '\n';
        for (int i = 1; i <= n / 2 + 1; i++) {
            cout << string(n / 2 + 1 - i, ' ') << '*' << string((i != 1) * (2 * i - 3), ' ') << string((i != 1), '*') << '\n';
        }
    }
    else {
        cout << "I LOVE CBNU";
    }
    return 0;
}
