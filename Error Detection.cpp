#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int tc, n, k;
    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        puts(__builtin_popcount(n) % 2 == k ? "Valid" : "Corrupt");
    }
    return 0;
}