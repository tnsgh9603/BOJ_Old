#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), [&](string a, string b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
        });
    cout << v[1] << '\n';
    return 0;
}