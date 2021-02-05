#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    fastio;
    int n; cin >> n;
    vector<int> v(9);
    vector<string> w{ "PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY" };
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < n; j++) {
            int t; cin >> t;
            v[i] = max(v[i], t);
        }
    }
    cout << w[max_element(v.begin(), v.end()) - v.begin()] << '\n';
}