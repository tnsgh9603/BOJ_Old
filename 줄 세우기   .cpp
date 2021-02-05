#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        v.insert(v.end() - t, i);
    }
    for (auto i : v) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}
