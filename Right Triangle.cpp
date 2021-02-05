#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int a;
    cin >> a;
    for (int i = 0; i < a; i++) {
        int b, c, d;
        cin >> b >> c >> d;
        vector<int> v = { b,c,d };
        sort(v.rbegin(), v.rend());
        cout << "Case #" << i + 1 << ": ";
        if (v[1] * v[1] + v[2] * v[2] == v[0] * v[0]) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}

