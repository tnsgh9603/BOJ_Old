#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    vector<int> v(3);
    for (int i = 0; i < 3; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    string s; {
        cin >> s;
    }
    for (int i = 0; i < 3; i++) {
        if (s[i] == 'A') {
            cout << v[0] << ' ';
        }
        if (s[i] == 'B') {
            cout << v[1] << ' ';
        }
        if (s[i] == 'C') {
            cout << v[2] << ' ';
        }
    }
    return 0;
}