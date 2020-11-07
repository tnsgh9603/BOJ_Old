#include <iostream>
using namespace std;
#define MOD 1000000000
int dp[101][10][1 << 10];
int main() {
    int N, i, j, k, ans = 0, full = (1 << 10) - 1;
    int cnt = 0;
    cin >> N;
    for (j = 1; j <= 9; j++) {
        dp[1][j][1 << j] = 1;
    }
    for (i = 2; i <= N; i++) {
        for (j = 0; j <= 9; j++) {
            for (k = 0; k <= full; k++) {
                if (j == 0) {
                    dp[i][0][k | (1 << 0)] = (dp[i][0][k | (1 << 0)] + dp[i - 1][1][k]) % MOD;
                }
                else if (j == 9)
                    dp[i][9][k | (1 << 9)] = (dp[i][9][k | (1 << 9)] + dp[i - 1][8][k]) % MOD;
                else {
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k]) % MOD;
                }
            }
        }
    }
    for (j = 0; j <= 9; j++) {
        ans = (ans + dp[N][j][full]) % MOD;
    }
    cout << ans % MOD;
    return 0;
}
