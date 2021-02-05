#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    bool ans[3]{ 1, 0, 0 };
    int v[3][2]{ 0, 1, 1, 2, 0, 2 };
    string s;
    cin >> s;
    for (auto i : s) {
        int t = i - 'A';

        swap(ans[v[t][0]], ans[v[t][1]]);
    }
    for (int i = 0; i < 3; i++) {
        if (ans[i]) {
            cout << i + 1 << '\n';
        }
    }
    return 0;
}