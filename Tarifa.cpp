#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int x, n; 
    cin >> x >> n;
    long long sum = x;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        sum += (x - t);
    }
    cout << sum << '\n';
    return 0;
}