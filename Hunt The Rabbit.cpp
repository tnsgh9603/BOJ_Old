#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    while (1) {
        int n;
        cin >> n;
        if (!n) {
            return 0;
        }
        int l = 1, r = 50;
        while (l <= r) {
            int mid = l + r >> 1;
            cout << mid << " ";
            if (mid == n) {
                break;
            }
            if (mid > n) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        puts("");
    }
    return 0;
}