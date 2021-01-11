#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bool visited[101][101];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
//3 -> 1, 1 -> 2, 2 -> 0, 0 -> 3
//¿À -> ¾Æ, ¾Æ -> ¿Þ, ¿Þ -> À§ , À§ -> ¿À
int set_direct(int d) {
    if (d == 3 || d == 2) {
        return (d + 2) % 4;
    }
    else {
        return 3 - d;
    }
}


int main() {

    int m, n;
    cin >> m >> n;

    int x = 0, y = 0;
    int d = 3;
    int ret = 0;

    while (1) {
        if (visited[x][y] == 1) {
            break;
        }
        visited[x][y] = 1;

        int nx = x + dx[d];
        int ny = y + dy[d];

        if (visited[nx][ny] == 1 || nx < 0 || ny < 0 || nx >= m || ny >= n) {
            d = set_direct(d);
            nx = x + dx[d];
            ny = y + dy[d];
            ret++;
        }

        x = nx;
        y = ny;
    }
    cout << ret - 1;
    return 0;
}
