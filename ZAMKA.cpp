#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int a, b, c; 
    cin >> a >> b >> c;
    auto f = [&](int n) {
        string s = to_string(n);
        int sum = 0;
        for (auto i : s) sum += i - '0';
        return sum == c;
    };
    for (int i = a; i <= b; i++) {
        if (!f(i)) {
            continue;
        }
        cout << i << '\n';
        break;
    }
    for (int i = b; i >= a; i--) {
        if (!f(i)) {
            continue;
        }cout << i << '\n';
        break;
    }
    return 0;
}