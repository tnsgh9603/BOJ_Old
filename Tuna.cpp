#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, x, sum = 0;
    cin >> n >> x;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        if (b - a <= x) {
            sum += b;
        }
        else {
            cin >> a, sum += a;
        }
    }
    cout << sum;
    return 0;
}