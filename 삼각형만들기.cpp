#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, cnt = 0; 
    cin >> n;
    for (int a = 1; a < n; a++) {
        for (int b = a; a + b < n; b++) {
            int c = n - a - b;
            if (c < b) {
                break;
            }
            if (a + b > c) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
