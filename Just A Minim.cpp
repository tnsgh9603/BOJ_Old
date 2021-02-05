#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    vector<double> v(17);
    v[0] = 2; v[1] = 1; v[2] = 0.5;
    v[4] = 0.25; v[8] = 0.125; v[16] = 0.0625;
    int n; 
    cin >> n;
    double sum = 0;
    while (n--) {
        int t;
        cin >> t;
        sum += v[t];
    }
    cout << fixed << setprecision(8) << sum << '\n';
    return 0;
}