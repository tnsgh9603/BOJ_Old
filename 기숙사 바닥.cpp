#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int a, b; 
    cin >> a >> b;
    a += b;
    for (int i = 3; i <= sqrt(a); i++) {
        if ((a / i - 2) * (i - 2) == b) {
            cout << a / i << ' ' << i << '\n';
            break;
        }
    }
    return 0;
}
