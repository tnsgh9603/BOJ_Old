#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int fence[101];
int main() {
    fastio;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = a; i < b; i++) {
        fence[i] = 1;
    }
    for (int i = c; i < d; i++) {
        fence[i] = 1;
    }
    int ans = 0;
    for (int i = 0; i <= 100; i++) {
        ans += fence[i];
    }
    cout << ans << '\n';
    return 0;
}