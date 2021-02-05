#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string a, b, s; 
    cin >> a >> b;
    int sz = min(a.size(), b.size());
    for (int i = 0; i < sz; i++) {
        s = to_string(a[a.size() - 1 - i] + b[b.size() - 1 - i] - 2 * '0') + s;
    }
    if (a.size() > b.size()) {
        s = a.substr(0, a.size() - b.size()) + s;
    }
    if (a.size() < b.size()) {
        s = b.substr(0, b.size() - a.size()) + s;
    }
    cout << s << '\n';
    return 0;
}