#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int a, b;
    cin >> a;
    while (cin >> b) {
        if (a > b) {
            cout << "Bad" << '\n';
            return 0;
        }
        a = b;
    }
    cout << "Good" << '\n';
    return 0;
}