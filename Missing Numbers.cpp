#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; 
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int mx = *max_element(v.begin(), v.end());
    if (mx == n) {
        cout << "good job" << '\n';
        return 0;
    }
    vector<int> check(mx + 1);
    for (auto i : v) {
        check[i] = 1;
    }
    for (int i = 1; i <= mx; i++) {
        if (!check[i]) {
            cout << i << '\n';
        }
    }
    return 0;
}