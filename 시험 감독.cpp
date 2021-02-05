#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    long long n;
    cin >> n;
    vector<long long> v;
    for (long long i = 0; i < n; i++) {
        long long a; 
        cin >> a;
        v.push_back(a);
    }
    long long b, c; 
    cin >> b >> c;
    long long ans = 0;
    for (auto i : v) {
        ans += 1 + (i - b > 0) * ((i - b - 1) / c + 1);
    }
    cout << ans;
    return 0;
}
