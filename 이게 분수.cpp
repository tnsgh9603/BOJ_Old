#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    double a[5],ans[4];
    for (int i = 1; i <= 4; i++) {
        cin >> a[i];
    }
    ans[0] = a[1] / a[3] + a[2] / a[4];
    ans[1] = a[3] / a[4] + a[1] / a[2];
    ans[2] = a[4] / a[2] + a[3] / a[1];
    ans[3] = a[2] / a[1] + a[4] / a[3];
    double temp2 = 0;
    int temp = 10;
    for (int i = 0; i < 4; i++) {
        if (temp2 < ans[i]) {
            temp2 = ans[i];
        }
    }
    for (int i = 0; i < 4; i++) {
        if (temp2 == ans[i]) {
            temp = min(temp, i);
        }
    }
    cout << temp << '\n';
}