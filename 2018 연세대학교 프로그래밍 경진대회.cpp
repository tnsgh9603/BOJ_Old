#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n;
    cin >> n;
    n--;
    for (int i = 1; i <= n; i++) {
        if (i * (i + 1) == n) {
            cout << i;
            return 0;
        }
    }
    return 0;
}