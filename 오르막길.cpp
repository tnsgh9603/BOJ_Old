#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, mx = 0; 
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 1, px = 0; i < n; i++) {
        if (v[i] > v[i - 1]) {
            mx = max(mx, v[i] - v[px]);
        }
        else {
            px = i;
        }
    }
    cout << mx;
    return 0;
}