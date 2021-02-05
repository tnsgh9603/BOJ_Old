#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; 
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b; 
        cin >> a >> b;
        cout << "Case " << i << ":";
        if (!a) {
            cout << ' ' << 0 << '\n';
        }
        else {
            if (a / b) {
                cout << ' ' << a / b;
            }
            if (a % b) {
                cout << ' ' << a % b << '/' << b;
            }
            cout << '\n';
        }
    }
    return 0;
}