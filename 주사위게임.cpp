#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, as = 100, bs = 100;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            bs -= a;
        }
        else if (a < b) {
            as -= b;
        }
    }
    cout << as << '\n' << bs << '\n';
    return 0;
}