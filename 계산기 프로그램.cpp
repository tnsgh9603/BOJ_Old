#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    long long num, ans = 0;
    char op;
    cin >> num;
    ans = num;
    while (1) {
        cin >> op;
        if (op == '=') {
            cout << ans << '\n';
            break;
        }
        cin >> num;
        if (op == '+') {
            ans += num;
        }
        else if (op == '-') {
            ans -= num;
        }
        else if (op == '*') {
            ans *= num;
        }
        else if (op == '/') {
            ans /= num;
        }
    }
    return 0;
}