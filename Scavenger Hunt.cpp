#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int> f(int x) {
    vector<int> ret;
    for (int i = 1; i <= x; i++) {
        if (x % i == 0) {
            ret.push_back(i);
        }
    }
    return ret;
}
int main() {
    fastio;
    int a, b;
    cin >> a >> b;
    for (auto i : f(a)){
        for (auto j : f(b)) {
            cout << i << ' ' << j << '\n';
        }
    }
    return 0;
}