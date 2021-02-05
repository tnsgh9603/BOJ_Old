#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N; 
    cin >> N;
    while (N--) {
        int n, mx = 0;
        cin >> n;
        vector<int> v(1001);
        for (int i = 0; i < n; i++) {
            char t;
            int a, b;
            cin >> t >> a >> b;
            mx = max(mx, b);
            for (int j = a; j < b; j++) {
                v[j]++;
            }
        }
        for (int i = 0; i < mx; i++) {
            if (v[i] > 0) {
                cout << char('A' + v[i] - 1);
            }
        }
        cout << '\n';
    }
    return 0;
}