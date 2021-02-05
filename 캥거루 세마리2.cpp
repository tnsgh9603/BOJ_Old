#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    while (1) {
        int A, B, C;
        cin >> A;
        if (cin.eof()) {
            return 0;
        }
        cin >> B >> C;
        int sum = B - A > C - B ? B - A - 1 : C - B - 1;
        cout << sum << "\n";
    }
    return 0;
}