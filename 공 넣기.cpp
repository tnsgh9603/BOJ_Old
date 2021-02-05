#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int arr[101];
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = a; j <= b; j++) {
            arr[j] = c;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}
