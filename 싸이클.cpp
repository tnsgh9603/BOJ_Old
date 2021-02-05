#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> v(1001);
    for (int i = 1, x = n; ; i++) {
        if (v[x]) { 
            cout << i - v[x] << '\n';
            break; 
        }
        v[x] = i;
        x = x * n % m;
    }
    return 0;
}
