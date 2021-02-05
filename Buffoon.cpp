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
    int t = v[0];
    bool flag = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] > t) {
            flag = 1;
        }
    }
    cout << (flag ? 'N' : 'S') << '\n';
    return 0;
}