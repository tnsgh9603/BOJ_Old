#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        stringstream in(s);
        int n, mx = 0;
        while (in >> n) {
            mx = max(n, mx);
        }
        cout << "Case #" << i + 1 << ": " << mx << '\n';
    }
    return 0;
}