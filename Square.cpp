#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += (long long int)i * i;
        }
        cout << sum << "\n";
    }
    return 0;
}