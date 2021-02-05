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
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = i + 1; j < n && v[j] < v[i]; j++) {
            cnt++;
        }
        mx = max(mx, cnt);
    }
    cout << mx;
    return 0;
}
