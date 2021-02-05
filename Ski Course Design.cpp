#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int INF = int(1e9);
int main() {
    fastio;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int mn = INF;
    for (int i = 0; i <= 83; i++) {
        int t = 0;
        for (int j = 0; j < n; j++) {
            if (v[j] < i) {
                t += (v[j] - i) * (v[j] - i);
            }
            if (v[j] > i + 17) {
                t += (v[j] - i - 17) * (v[j] - i - 17);
            }
        }
        mn = min(mn, t);
    }
    cout << mn;
    return 0;
}