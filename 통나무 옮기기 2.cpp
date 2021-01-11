#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int mp[33][33];
long long arr[3][33][33];
int main() {
    fastio;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> mp[i][j];
        }
    }
    arr[0][1][2] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            // 1이면 막힌 경우이므로 0일때만
            if (!mp[i][j + 1]) {
                arr[0][i][j + 1] += arr[0][i][j] + arr[2][i][j];
            }
            if (!mp[i + 1][j]) {
                arr[1][i + 1][j] += arr[1][i][j] + arr[2][i][j];
            }
            if (!mp[i + 1][j + 1] && !mp[i + 1][j] && !mp[i][j + 1]) {
                arr[2][i + 1][j + 1] += arr[0][i][j] + arr[1][i][j] + arr[2][i][j];
            }
        }
    }
    cout << arr[0][n][n] + arr[1][n][n] + arr[2][n][n];
    return 0;
}