#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n;
    while (cin >> n && n) {
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        v.erase(unique(v.begin(), v.end()), v.end());
        for (auto i : v) {
            cout << i << ' ';
        }
        cout << "$\n";
    }
    return 0;
}
