#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        bool flag = 1;
        vector<int> v(11);
        for (int j = 1; j <= 10; j++) {
            cin >> v[j];
            if (v[j] != (j - 1) % 5 + 1) {
                flag = 0;
            }
        }
        if (flag) {
            cout << i + 1 << '\n';
        }
    }
    return 0;
}