#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std; 
int main() {
    fastio;
    int t, d, n, s, p;
    cin >> t;
    while (t--) {
        cin >> d >> n >> s >> p;
        if (d + n * p < n * s) {
            cout << "parallelize\n";
        }
        else if (d + n * p > n * s) {
            cout << "do not parallelize\n";
        }
        else {
            cout << "does not matter\n";
        }
    }
    return 0;
}
