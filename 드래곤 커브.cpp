#include <iostream>
#include <cmath>
using namespace std;
int main() {
    // → - 0, ↑ - 1, ← - 2, ↓ - 3
    int n;
    cin >> n;
    int pattern[4][1024];
    bool visited[101][101] = { 0, };

    pattern[0][0] = 0; // 첫 방향이 0 일때 처음일 때 배열 처음에 방향 0을 넣어줌 
    pattern[1][0] = 1; // 첫 방향이 1 일때 처음일 때 배열 처음에 방향 1을 넣어줌
    pattern[2][0] = 2; // 첫 방향이 2 일때 처음일 때 배열 처음에 방향 2을 넣어줌
    pattern[3][0] = 3; // 첫 방향이 3 일때 처음일 때 배열 처음에 방향 3을 넣어줌

    // 드래곤 커브 셋팅 , 방향별로 0~10세대 까지 셋팅
    for (int k = 0; k < 4; k++) {
        for (int i = 1; i <= 10; i++) {
            int start = pow(2, i - 1); // pow함수의 리턴형은 double이라서 형변환을 해주었다. 안해줘도 되긴함
            int end = pow(2, i);
            for (int j = start, l = 1; j < end; j++, l += 2) {
                pattern[k][j] = pattern[k][j - l] + 1 == 4 ? 0 : pattern[k][j - l] + 1;
            }
        }
    }

    // 드래곤 커브 그리기
    int x, y, d, g; 
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> d >> g;
        int end = (int)pow(2, g);
        visited[x][y] = true;

        for (int j = 0; j < end; j++) {
            if (pattern[d][j] == 0) {
                x++;
            }
            else if (pattern[d][j] == 1) {
                y--;
            }
            else if (pattern[d][j] == 2) {
                x--;
            }
            else {
                y++;
            }
            visited[x][y] = true;
        }
    }

    // 배열 탐색
    int cnt = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (visited[i][j] && visited[i][j + 1] && visited[i + 1][j] && visited[i + 1][j + 1]) {
                cnt++;
            }
        }
    }
    cout << cnt;
}