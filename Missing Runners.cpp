#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; 
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n - 1; i++) {
        int t;
        cin >> t;
        v[--t]++;
    }
    cout << find(v.begin(), v.end(), 0) - v.begin() + 1 << '\n';
    return 0;
}