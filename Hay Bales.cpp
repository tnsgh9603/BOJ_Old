#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
long long ans, total;
int main() {
    fastio;
    int n;
    cin >> n;
    vector<int>arr(n);
    for (auto& a : arr) {
        cin >> a;
    }
    for (auto a : arr) {
        total += a;
    }
    total /= n;
    for (auto a : arr) {
        if (total > a) {
            ans += total - a;
        }
    }
    cout << ans;
    return 0;
}