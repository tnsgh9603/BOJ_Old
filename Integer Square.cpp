#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i * i + j * j == n) {
                printf("0 0\n");
                printf("%d %d\n", i, j);
                printf("%d %d\n", i + j, j - i);
                printf("%d %d\n", j, -i);
                return 0;
            }
        }
    }
    cout << "Impossible";
    return 0;
}