#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, h = 0, block = 0;
    cin >> n;
    while (block <= n) {
        block += 2 * h * h + 2 * h + 1;
        h++;
    }
    cout << h - 1;
    return 0;
}