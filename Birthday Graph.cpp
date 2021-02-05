#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, cnt = 0;
    vector<string> t{ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    while (cin >> n && n) {
        vector<int> v(12);
        while (n--) {
            int a, b, c;
            cin >> a >> b >> c;
            v[b - 1]++;
        }
        cout << "Case #" << ++cnt << ":\n";
        for (int i = 0; i < 12; i++) {
            cout << t[i] << ':' << string(v[i], '*') << '\n';
        }
    }
    return 0;
}