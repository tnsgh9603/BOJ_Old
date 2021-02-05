#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    long long a, b, t = 1; 
    cin >> a >> b;
    for (int i = 0; i < b; i++) {
        t *= 10;
    }
    cout << int(round(1.0 * a / t) * t);
    return 0;
}