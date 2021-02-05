#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
int main() {
    fastio;
    ll n;
    while (cin >> n && n) {
        ll sum = 0;
        for (ll i = 1; i < n; i++) {
            if (n % i == 0) {
                sum += i;
            }
        }
        cout << n << ' ' << (n != sum ? n < sum ? "ABUNDANT" : "DEFICIENT" : "PERFECT") << '\n';
    }
    return 0;
}