#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    fastio;
    double sum; int n; cin >> sum >> n;
    vector<int> v(101), w(3);
    while (n--) {
        int t; char c; cin >> t >> c;
        if (c == 'L') {
            for (int i = t - 1; i >= 1; i--) {
                v[i]++;
            }
        }
        else {
            for (int i = t + 1; i <= 100; i++) {
                v[i]++;
            }
        }
    }
    for (int i = 1; i <= 100; i++) {
        w[v[i] % 3]++;
    }
    cout << fixed << setprecision(2);
    for (int i = 0; i < 3; i++) {
        cout << sum * w[i] / 100 << '\n';
    }
}