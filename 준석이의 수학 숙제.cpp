#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int a[80001];
int main() {
    fastio;
    for (int i = 1; i < 80001; ++i) {
        a[i] = a[i - 1] + (i % 3 == 0 || i % 7 == 0 ? i : 0);
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        cout << a[n] << "\n";
    }
    return 0;
}
