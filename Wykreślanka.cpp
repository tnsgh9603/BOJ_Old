#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, cnt = 0, t = 1;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        if (v[i] != t) {
            cnt++;
        }
        else {
            t++;
        }
    }
    cout << cnt;
    return 0;
}