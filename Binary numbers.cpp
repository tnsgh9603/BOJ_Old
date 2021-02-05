#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i < 32; i++) {
        if (n & 1 << i) {
            cout << i << ' ';
        }
    }
    return 0;
}