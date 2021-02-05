#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j < n; j++) {
            if (v[j] % i > v[j + 1] % i) {
                swap(v[j], v[j + 1]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << v[i] << "\n";
    }
    return 0;
}