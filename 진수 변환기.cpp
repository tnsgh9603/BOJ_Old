#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    fastio;
    int n, m; cin >> n >> m;
    if (!n) {
        cout << 0 << '\n';
        return 0;
    }
    vector<char> v;
    while (n) {
        int t = n % m;
        v.push_back(t >= 10 ? t - 10 + 'A' : t + '0');
        n /= m;
    }
    for (int i = v.size() - 1; i >= 0; i--) cout << v[i];
    cout << '\n';
}