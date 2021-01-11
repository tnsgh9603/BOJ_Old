#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<vector<int>> vec;
typedef struct drone {
public :
    int row;
    int col;
    int direction;
    int time;
    // 생성자 함수
    drone(int a, int b, int c, int d) {
        row = a;
        col = b;
        direction = c; 
        time = d;
    }
}drone;

int turn_row[2][4] = { {0,0,-1,-1},{1,1,0,0} };
int turn_col[2][4] = { {0,1,0,1},{0,-1,0,-1} };
int visited[2][101][101];

queue <drone> q;

bool check_end(drone now, int n) {
    if (now.direction == 0) {
        if (now.row == n - 1 && now.col + 1 == n - 1) {
            return true;
        }
    }
    else {
        if (now.row + 1 == n - 1 && now.col == n - 1) {
            return true;
        }
    }
    return false;
}

bool can_move(int r, int c, int d, vec board) {
    int b_size = board.size();
    if (r < 0 || r >= b_size || c < 0 || c >= b_size || board[r][c] == 1) {
        return false;
    }
    if (d == 0) {
        if (c + 1 >= b_size || board[r][c + 1] == 1) {
            return false;
        }
    }
    else {
        if (r + 1 >= b_size || board[r + 1][c] == 1)
            return false;
    }
    return true;
}

bool can_turn(drone now, int next_row, int next_col, vec board) {
    int b_size = board.size();
    // 가로에서 세로로 회전
    if (now.direction == 0) { 
        //아래로 돌리는 회전
        if (now.row == next_row) { 
            //범위 벗어나거나 둘 중 하나라도 벽일때
            if (now.row + 1 >= b_size || (board[now.row + 1][now.col] || board[now.row + 1][now.col + 1])) {
                return false;
            }
        }
        // 위로 돌리는 회전
        else { 
            if (now.row - 1 < 0 || (board[now.row - 1][now.col] || board[now.row - 1][now.col + 1])) {
                return false;
            }
        }
    }
    // 세로에서 가로로
    else {
        if (now.col == next_col) {//오른쪽으로 돌리는 회전
            if (now.col + 1 >= b_size) {
                return false;
            }
            if (board[now.row][now.col + 1] || board[now.row + 1][now.col + 1]) {
                return false;
            }
        }
        else {
            if (now.col - 1 < 0) {
                return false;
            }
            if (board[now.row][now.col - 1] || board[now.row + 1][now.col - 1]) {
                return false;
            }
        }
    }
    return true;
}

int bfs(vec board) {
    q.push(drone(0, 0, 0, 0));
    while (!q.empty()) {
        drone now = q.front();
        q.pop();
        // 목적지에 도착했다면 종료
        if (check_end(now, board.size())) {
            return now.time;
        }
        // 4방향 이동
        for (int i = 0; i < 4; i++) {
            int next_row = now.row + "2101"[i] - '1';
            int next_col = now.col + "1012"[i] - '1';
            // 이동할 수 없거나 이미 방문했을 경우 무시
            if (!can_move(next_row, next_col, now.direction, board) || (visited[now.direction][next_row][next_col])) {
                continue;
            }
            visited[now.direction][next_row][next_col] = true;
            q.push(drone(next_row, next_col, now.direction, now.time + 1));
        }
        // 회전
        for (int i = 0; i < 4; i++) { // 4가지 방법의 회전
            int next_direction = now.direction ^ 1; // XOR연산을 통해 방향 뒤집기
            int next_row = now.row + turn_row[now.direction][i];
            int next_col = now.col + turn_col[now.direction][i];
            // 회전불가능하거나 이미 방문했을 경우 무시
            if (!can_turn(now, next_row, next_col, board) || (visited[next_direction][next_row][next_col])) {
                continue;
            }
            // 방문 체크
            visited[next_direction][next_row][next_col] = true;
            q.push(drone(next_row, next_col, next_direction, now.time + 1));
        }
    }
}

int solution(vec board) {
    return bfs(board);
}