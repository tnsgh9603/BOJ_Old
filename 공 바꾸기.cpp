#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);
    iota(v.begin(), v.end(), 0);
    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b;
        int temp = v[a];
        v[a] = v[b];
        v[b] = temp;
    }
    for (int i = 1; i <= n; i++) {
        cout << v[i] << ' ';
    }
    return 0;
}
