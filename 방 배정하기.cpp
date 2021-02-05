#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, a, b, c; 
    cin >> a >> b >> c >> n;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 100; k++) {
                if ((i * a + j * b + k * c) == n) {
                    cout << 1;
                    return 0;
                }
            }
        }
    }
    cout << 0;
    return 0;
}