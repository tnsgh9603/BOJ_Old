#include <iostream>
#include <algorithm>
using namespace std;

int N;
int ans[2]; // 체스판에서 흰색판과 검은색 판을 따로 고려해줌
int chess[11][11];
int l[20]; // ↗↙ 방향에 비숍이 놓여져 있는가. (l 배열로 표현)
int r[20]; // ↖↘ 방향에 비숍이 놓여져 있는가. (r 배열로 표현)

// 놓을 수 있는 비숍의 최대개수를 구하는 함수
// 흑/백, 두 가지 경우로 나누어 계산
void tracking(int row, int col, int count, int color) {
    if (col >= N) { // 열이 범위를 초과하면 다음 행으로 이동 
        row++;
        if (col % 2 == 0) {
            col = 1;
        }
        else {
            col = 0;
        }
    }
    if (row >= N) { // 끝까지 탐색한경우
        ans[color] = max(ans[color], count); // 크기 비교해서 갱신해줌
        return;
    }
    // ↗↙ 방향에서는 row+col의 값이 같다. (l 배열로 표현)
    // ↖↘ 방향에서는 col-row의 값이 같다. (r 배열로 표현)
    // 인덱스 부분을 0부터 고려해주기 위해 N-1을 +해주었다.
    if (chess[row][col] && !l[col - row + N - 1] && !r[row + col]) { // chess[row][col]의 값이 0이 아니고 각 대각선 방향에 퀸이 없는경우
        l[col - row + N - 1] = r[row + col] = 1; // 방문 표시 (퀸을 놓음)
        tracking(row, col + 2, count + 1, color); // 해당 자리에 퀸을 놓고 다음을 탐색함
        l[col - row + N - 1] = r[row + col] = 0; // 초기화 
    }
    tracking(row, col + 2, count, color); // 해당 자리에 퀸을 놓지 않고 다음을 탐색힘
    // 검은색은 검은색판끼리, 흰색은 흰색판끼리 고려하기 위해 col + 2 를 해줌
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> chess[i][j];
        }
    }

    tracking(0, 0, 0, 0);
    tracking(0, 1, 0, 1);

    cout << ans[0] + ans[1];

    return 0;
}