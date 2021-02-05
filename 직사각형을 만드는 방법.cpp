#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, r = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i; i * j <= n; j++) {
            r++;
        }
    }
    cout << r;
    return 0;
}