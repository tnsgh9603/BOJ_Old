#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    int n, c, m, s, t = 0;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        scanf("%d:%d", &m, &s);
        t += 60 * m + s;
    }
    t -= (n - 1) * c;
    printf("%02d:%02d:%02d", t / 3600, t % 3600 / 60, t % 3600 % 60);
    return 0;
}