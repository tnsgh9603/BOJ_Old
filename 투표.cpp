#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> v(n), cnt(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    while (m--) {
        int t; 
        cin >> t;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] <= t) {
                cnt[i]++;
                break;
            }
        }
    }
    cout << max_element(cnt.begin(), cnt.end()) - cnt.begin() + 1;
    return 0;
}