#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
char m[11];
int main() {
    fastio;
    scanf("%*d %s", m);
    for (int i = 1; m[i]; ++i) {
        if (m[i - 1] == m[i]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}