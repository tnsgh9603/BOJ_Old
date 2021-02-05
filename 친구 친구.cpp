#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a - 1]++, v[b - 1]++;
    }
    for (auto i : v) {
        cout << i << '\n';
    }
    return 0;
}