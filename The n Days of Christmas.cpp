#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
ll v[1000001];
int main() {
    fastio;
    for (ll i = 1, t = 0; i <= 1000000; i++) {
        v[i] = v[i - 1] + (t += i);
    }
    int n;
    while (cin >> n && n) {
        cout << v[n] << '\n';
    }
    return 0;
}