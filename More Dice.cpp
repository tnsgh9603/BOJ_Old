#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cout << "Case " << i << ":\n";
        int n;
        cin >> n;
        for (int i = 1; i <= n - i; i++) {
            if (i < 1 || i > 6 || n - i < 1 || n - i > 6) {
                continue;
            }
            cout << '(' << i << ',' << n - i << ')' << '\n';
        }
    }
    return 0;
}