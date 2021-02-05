#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    char a[10001], b[10001];
    long long cnt = 0;
    cin >> a >> b;
    int i, j, t = 0;

    for (i = 0; b[i]; i++) {
        t += b[i] - '0';
    }
    long long sol = 0;
    for (i = 0; a[i]; i++) {
        sol += (a[i] - '0') * t;
    }
    cout << sol;
    return 0;
}