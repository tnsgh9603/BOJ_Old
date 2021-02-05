#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    unsigned long long n;
    cin >> n;
    n = (1LL << 64) - n;
    for (int i = 0; i <= 64; i++) {
        if (n == (1LL << i)) {
            cout << 64 - i;
            return 0;
        }
    }
    return 0;
}
