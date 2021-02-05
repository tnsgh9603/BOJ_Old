#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    vector<int> v(31);
    v[1] = 1;
    for (int i = 2; i <= 30; i++) {
        v[i] = 2 * v[i - 1] + 1;
    }
    int n;
    cin >> n;
    while (n--) {
        int t;
        cin >> t;
        cout << v[t] << '\n';
    }
    return 0;
}