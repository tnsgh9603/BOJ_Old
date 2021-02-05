#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    double a[5] = { 350.34,230.9,190.55,125.3,180.9 }, sum;
    int n;
    cin >> n;
    while (n--) {
        sum = 0;
        for (int i = 0; i < 5; i++) {
            double x;
            cin >> x;
            sum += a[i] * x;
        }
        cout << "$" << fixed << setprecision(2) << sum << "\n";
    }
}