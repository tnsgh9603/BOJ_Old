#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, sum = 0; 
    cin >> n;
    auto f = [&]() {
        sum = 0;
        string s = to_string(n);
        for (auto i : s) sum += i - '0';
    };
    f();
    while (1) {
        if (n % sum) {
            n++, f();
        }
        else {
            cout << n << '\n';
            break;
        }
    }
    return 0;
}