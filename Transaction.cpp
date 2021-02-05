#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    while (1) {
        int a, b;
        char str[2] = { 0 };
        scanf("%d %s %d", &a, str, &b);
        if (str[0] == 'W') {
            if (!a && !b) { 
                break;
            }
            if (a - b >= -200) {
                cout << a - b << "\n";
            }
            else {
                cout << "Not allowed\n";
            }
        }
        if (str[0] == 'D') {
            cout << a + b << "\n";
        }
    }
    return 0;
}
