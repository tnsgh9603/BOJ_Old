#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int a1, a2, a3;
    while (1) {
        cin >> a1 >> a2 >> a3;
        if (a1 == 0 && a2 == 0 && a3 == 0) {
            break;
        }
        if (a2 - a1 == a3 - a2) {
            printf("AP %d\n", a3 + a2 - a1);
        }
        else {
            printf("GP %d\n", a3 * a2 / a1);
        }
    }
    return 0;
}
