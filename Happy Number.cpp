#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    set<int> visited;
    int n;
    cin >> n;
    auto f = [&](int n) {
        int ret = 0;
        for (auto i : to_string(n)) {
            ret += (i - '0') * (i - '0');
        }
        return ret;
    };
    visited.insert(n);
    while (1) {
        n = f(n);
        if (n == 1) {
            cout << "HAPPY" << '\n';
            return 0;
        }
        if (visited.count(n)) {
            cout << "UNHAPPY" << '\n';
            return 0;
        }
        visited.insert(n);
    }
    return 0;
}