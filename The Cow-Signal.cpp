#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
char ans[101][101];
int main() {
    fastio;
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            for (int k = K * i; k < K * i + K; k++) {
                for (int l = K * j; l < K * j + K; l++) {
                    ans[k][l] = c;
                }
            }
        }
    }
    for (int i = 0; i < K * N; i++) {
        for (int j = 0; j < K * M; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    return 0;
}