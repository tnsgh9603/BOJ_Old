#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int a, b;
    float m, res;
    cin >> a >> b;
    m = (b - a);
    m /= 400;
    res = 1 / (1 + pow(10, m));
    cout << res;
    return 0;
}