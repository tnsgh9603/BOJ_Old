#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int a[5], b[5];
int main() {
    fastio;
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 5; i++) {
        cin >> b[i];
    }
    bool yes = true;
    for (int i = 0; i < 5; i++) {
        if (a[i] + b[i] != 1) {
            yes = false;
            break;
        }
    }
    yes ? cout << 'Y' : cout << 'N';
    return 0;
}