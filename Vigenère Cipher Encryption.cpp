#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int board[26][26];
int main() {
    fastio;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            board[i][j] = 'A' + (i + j + 1) % 26;
        }
    }
    string a, b;
    while (cin >> a && a != "0") {
        cin >> b;
        for (int i = 0; i < b.size(); i++) {
            cout << char(board[a[i % a.size()] - 'A'][b[i] - 'A']);
        }
        cout << '\n';
    }
    return 0;
}
