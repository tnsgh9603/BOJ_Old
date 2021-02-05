#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int A, B;
    cin >> A >> B;
    for (int i = A + 1; i <= 62; i++) {
        long long n = 1;
        int power = i;
        while (power--) {
            n *= 2;
        }
        while (n > 9) {
            n /= 10;
        }
        if (n == B) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}