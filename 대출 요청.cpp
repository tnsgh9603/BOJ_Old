#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; 
    cin >> n;
    vector<int> v(32);
    while (n--) {
        int a, b;
        cin >> a >> b;
        for (int i = a; i < b; i++) {
            v[i]++;
        }
    }
    int m; 
    cin >> m;
    for (auto i : v) {
        if (i > m) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}
