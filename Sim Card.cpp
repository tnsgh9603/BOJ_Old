#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    while (1) {
        int a, b; 
        cin >> a >> b;
        if (!a && !b) {
            break;
        }
        int mn = 30 * a + 40 * b;
        mn = min(mn, 35 * a + 30 * b);
        mn = min(mn, 40 * a + 20 * b);
        cout << mn << '\n';
    }
    return 0;
}