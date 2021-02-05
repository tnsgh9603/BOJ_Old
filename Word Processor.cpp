#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, k; 
    cin >> n >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n;) {
        int t = 0;
        string s;
        while (i < n && (t += v[i].size()) <= k) {
            s += v[i++] + ' ';
        }
        s.pop_back();
        cout << s << '\n';
    }
    return 0;
}