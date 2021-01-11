#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int deliver[3], ans[3];
int main() {
    fastio;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = 0; i < 3; i++) {
        cin >> deliver[i];
        int dog1 = deliver[i] % (a + b);
        int dog2 = deliver[i] % (c + d);
        if (dog1 <= a && dog1 != 0) {
            ans[i]++;
        }
        if (dog2 <= c && dog2 != 0) {
            ans[i]++;
        }
    }
    for (int i = 0; i < 3; i++) {
        cout << ans[i] << '\n';
    }
}