#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
long long func(int a, char x, int b) {
    if (x == '+') {
        return a + b;
    }
    else if (x == '-') {
        return a - b;
    }
    else if (x == '*') {
        return a * b;
    }
    else {
        return a / b;
    }
}
int main() {
    fastio;
    int a, b, c;
    char x, y;
    long long ans1, ans2;
    cin >> a >> x >> b >> y >> c;
    ans1 = func(func(a, x, b), y, c);
    ans2 = func(a, x, func(b, y, c));
    cout << min(ans1, ans2) << '\n' << max(ans1, ans2);
    return 0;
}​