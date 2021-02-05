#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
char v[100][100];
int main() {
    fastio;
    int n;
    cin >> n;
    while (n--) {
        memset(v, 0, sizeof(v));
        string s;
        cin >> s;
        int sz = 1;
        while (sz * sz < s.size()) {
            sz++;
        }
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                if (i * sz + j < s.size()) {
                    v[j][sz - 1 - i] = s[i * sz + j];
                }
            }
        }
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                if (v[i][j]) {
                    cout << v[i][j];
                }
            }
        }
        cout << '\n';
    }
    return 0;
}