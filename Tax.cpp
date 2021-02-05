#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    while (1) {
        int n;
        cin >> n;
        if (!n) {
            break;
        }
        if (n <= 1000000) {
            cout << n << "\n";
        }
        else if (n <= 5000000) {
            cout << int(n * (0.9)) << "\n";
        }
        else {
            cout << int(n * (0.8)) << "\n";
        }
    }
    return 0;
}
