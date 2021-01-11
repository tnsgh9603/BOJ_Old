#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b == c) {
        printf("%d+%d=%d", a, b, c);
    }
    else if (a - b == c) {
        printf("%d-%d=%d", a, b, c);
    }
    else if (a * b == c) {
        printf("%d*%d=%d", a, b, c);
    }
    else if (a == b * c) {
        printf("%d/%d=%d", a, b, c);
    }
    else if (a == b - c) {
        printf("%d=%d-%d", a, b, c);
    }
    else {
        printf("%d=%d/%d", a, b, c);
    }
    return 0;
}