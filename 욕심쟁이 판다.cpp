#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int dp[501][501], arr[501][501], n, ans;
int dfs(int x, int y) {
    // �̹� ���س��ٸ� �ٷ� �Ѱ���
    if (dp[x][y]) {
        return dp[x][y];
    }
    // ó������ ���� 1
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        // �����¿� �̵�
        int nx = x + "1120"[i] -'1';
        int ny = y + "2011"[i] -'1';
        // ���� �Ѿ�� ����
        if (ny < 1 || ny > n || nx < 1 || nx > n) {
            continue;
        }
        // ������ �� �پ��� ��� ����
        if (arr[x][y] >= arr[nx][ny]) {
            continue;
        }
        // �̵��� �ٽ� dfs�ݺ�
        dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
    }
    return dp[x][y];
}
int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans;
    return 0;
}
