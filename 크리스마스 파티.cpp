#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (auto& i : v) {
        cin >> i;
    }
    vector<int> score(n);
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            int t;
            cin >> t;
            if (t != v[i]) {
                cnt++;
            }
            else {
                score[j]++;
            }
        }
        score[v[i] - 1] += cnt;
    }
    for (auto i : score) {
        cout << i << '\n';
    }
    return 0;
}
