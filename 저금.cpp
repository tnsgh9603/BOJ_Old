#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    fastio;
    double a, b, c;
    while (cin >> a >> b >> c) {
        int cnt = 0;
        b = 1 + b / 100;
        while (a < c) {
            a *= b;
            cnt++;
        }
        cout << cnt << '\n';
    }
}