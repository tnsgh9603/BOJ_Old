#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, m, start = 0;
    cin >> n >> m;
    for (int i = 0; i <= 3599; i++) {
        int a1 = i / 60;
        int a2 = i % 60;
        if (a1 % 10 == m || a1 / 10 == m || a2 % 10 == m || a2 / 10 == m) {
            start++;
        }
    }
    int re = 0;
    for (int i = 0; i <= n; i++) {
        if (i % 10 == m || i / 10 == m) {
            re += 3600;
        }
        else {
            re += start;
        }
    }
    cout << re;
    return 0;
}