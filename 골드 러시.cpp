#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N; cin >> N;
    while (N--) {
        long long n, a, b; cin >> n >> a >> b;
        cout << n - __builtin_ctzll(a) << '\n';
    }
}