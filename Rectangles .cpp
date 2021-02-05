#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int a, b, c, d;
    while (1) {
        cin >> a >> b >> c;
        if (!a && !b && !c) {
            break;
        }
        if (!a){
            a = c / b;
        }
        if (!b) {
            b = c / a;
        }
        c = a * b;
        cout << a << " " << b << " " << c << "\n";
    }
    return 0;
}
