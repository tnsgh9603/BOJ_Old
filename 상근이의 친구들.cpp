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
        cout << a + b << '\n';
    }
    return 0;
}