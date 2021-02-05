#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        v[i] = i;
    }
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> temp = v;
        for (int i = c; i <= b; i++) {
            v[i - (c - a)] = temp[i];
        }
        for (int i = a; i < c; i++) {
            v[i + (b - c + 1)] = temp[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << v[i] << ' '; 
    }
    return 0;
}