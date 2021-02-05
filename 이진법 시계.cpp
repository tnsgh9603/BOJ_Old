#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n;
    cin >> n;
    while (n--) {
        string t;
        cin >> t;
        for (auto& i : t) {
            if (i == ':') {
                i = ' ';
            }
        }
        stringstream in(t); 
        int h, m, s; in >> h >> m >> s;
        for (int j = 5; j >= 0; j--) {
            cout << bool((h & 1 << j) == 1 << j) << bool((m & 1 << j) == 1 << j) << bool((s & 1 << j) == 1 << j);
        }
        cout << ' ';
        for (int j = 5; j >= 0; j--) {
            cout << bool((h & 1 << j) == 1 << j);
        }
        for (int j = 5; j >= 0; j--) {
            cout << bool((m & 1 << j) == 1 << j);
        }
        for (int j = 5; j >= 0; j--) {
            cout << bool((s & 1 << j) == 1 << j);
        }
        cout << '\n';
    }
    return 0;
}
