#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, a[7], sum, min;
    cin >> n;
    while (n--) {
        sum = 0;
        min = 101;
        for (int i = 0; i < 7; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) {
                sum += a[i];
                if (a[i] < min) {
                    min = a[i];
                }
            }
        }
        cout << sum << ' ' << min << '\n';
    }
}