#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    double a, b, n, cnt;
    cin >> n;
    cnt = n;
    while (1) {
        cin >> a;
        if (a == 999) {
            break;
        }
        cout << fixed << setprecision(2) << a - cnt << "\n";
        cnt = a;
    }
}