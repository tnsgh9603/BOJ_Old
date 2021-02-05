#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int n, cnt = 0;
        cin >> n;
        string a, b; cin >> a >> b;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                cnt++;
            }
        }
        cout << "Case " << i << ": " << cnt << '\n';
    }
    return 0;
}