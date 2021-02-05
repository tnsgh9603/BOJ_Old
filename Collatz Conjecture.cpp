#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n;
    cin >> n;
    cout << n << " ";
    while (1) {
        if (n == 1) {
            break;
        }
        else if (n % 2 == 0) {
            n = n / 2;
            cout << n << " ";
        }
        else {
            n = n * 3 + 1;
            cout << n << " ";
        }
    }
    return 0;
}
