#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int board[3][3];

bool check() {
    for (int i = 0; i < 3; i++) {
        bool flag = 1;
        if (!board[i][0]) continue;
        for (int j = 0; j < 3; j++) {
            if (board[i][0] != board[i][j]) flag = 0;
        }
        if (flag) return 1;
    }
    for (int j = 0; j < 3; j++) {
        bool flag = 1;
        if (!board[0][j]) continue;
        for (int i = 0; i < 3; i++) {
            if (board[0][j] != board[i][j]) flag = 0;
        }
        if (flag) return 1;
    }
    if (board[0][0] && board[0][0] == board[1][1] && board[1][1] == board[2][2] ||
        board[2][0] && board[2][0] == board[1][1] && board[1][1] == board[0][2]) return 1;
    return 0;
}

int main() {
    fastio;
    int t; cin >> t;
    for (int i = 0; i < 9; i++) {
        int a, b; cin >> a >> b; --a, --b;
        board[a][b] = i & 1 ? (t & 1) + 1 : t;
        if (check()) {
            cout << board[a][b] << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
}