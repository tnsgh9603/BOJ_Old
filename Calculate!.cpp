#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int a, b;
    string c;
    cin >> a >> b;
    cin >> c;
    //XOR는 2번하면 자기 자신으로 돌아온다
    if ((c[c.size() - 1] - '0') % 2 == 0) {
        cout << a << '\n';
    }
    else {
        int ans = a ^ b;
        cout << ans << '\n';
    }
    return 0;
}