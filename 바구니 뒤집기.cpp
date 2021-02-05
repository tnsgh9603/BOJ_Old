#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    while (m--) {
        int a, b; 
        cin >> a >> b;
        reverse(v.begin() + a - 1, v.begin() + b);
    }
    for (auto i : v) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}