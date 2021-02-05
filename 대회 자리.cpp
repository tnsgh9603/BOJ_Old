#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N; 
    cin >> N;
    while (N--) {
        int n, m, sum = 0;
        cin >> n >> m;
        vector<bool> v(m + 1);
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            if (!v[t]) {
                v[t] = 1;
            }
            else {
                sum++;
            }
        }
        cout << sum << '\n';
    }
    return 0;
}
