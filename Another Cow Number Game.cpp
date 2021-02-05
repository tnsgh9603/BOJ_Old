#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    long long n, cnt = 0; 
    cin >> n;
    while (n != 1) {
        cnt++;
        if (n & 1) {
            n = 3 * n + 1;
        }
        else {
            n /= 2;
        }
    }
    cout << cnt << '\n';
    return 0;
}