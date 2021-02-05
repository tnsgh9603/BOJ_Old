#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string a, b;
        cin >> a >> b;
        cout << "Case " << i << ": " << b << ", " << a << '\n';
    }
    return 0;
}