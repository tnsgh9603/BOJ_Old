#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 1; i <= c; i++) {
        if (i % a == 0 && i % b == 0) {
            cout << "FizzBuzz" << '\n';
        }
        else if (i % a == 0) {
            cout << "Fizz" << '\n';
        }
        else if (i % b == 0) {
            cout << "Buzz" << '\n';
        }
        else {
            cout << i << '\n';
        }
    }
    return 0;
}