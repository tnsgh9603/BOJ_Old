#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    vector<int> v(5);
    for (int i = 1; i < 5; i++) {
        cin >> v[i], v[i] += v[i - 1];
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << abs(v[i] - v[j]) << ' ';
        }
        cout << '\n';
    }
    return 0;
}