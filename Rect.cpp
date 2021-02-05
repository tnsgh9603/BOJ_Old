#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int board[10001][10001];
int main() {
    fastio;
    int n; 
    cin >> n;
    for (int t = 0; t < n; t++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = a; i < b; i++) {
            for (int j = c; j < d; j++) {
                board[i][j]++;
            }
        }
    }
    cout << count(board[0], board[10001], n);
    return 0;
}