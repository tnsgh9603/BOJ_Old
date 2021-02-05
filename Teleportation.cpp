#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int a, b, c, d, arr[2], brr[2];
    cin >> a >> b >> c >> d;
    arr[0] = abs(a - c), arr[1] = abs(a - d), brr[0] = abs(b - c), brr[1] = abs(b - d);
    sort(&arr[0], &arr[2]);
    sort(&brr[0], &brr[2]);
    if (arr[0] + brr[0] >= abs(a - b)) {
        cout << abs(a - b);
    }
    else {
        cout << arr[0] + brr[0];
    }
    return 0;
}