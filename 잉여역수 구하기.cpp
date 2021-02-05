#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int a, b, i = 1;
    cin >> a >> b;
    while (1) {
        if (a * i % b == 1) {
            cout << i;
            return 0;
        }
        i++;
    }
    return 0;
}