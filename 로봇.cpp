#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N;
int robot[101][101]; 
bool visited[101][101][5]; // 방문한 거 체크
vector<pair<pair<int, int>, int >> from, to;

bool go_k(int x, int y, int d, int k){
    int nx = x + ("1120"[d - 1] - '1') * k; // k는 최대 3
    int ny = y + ("2011"[d - 1] - '1') * k;

    if (nx < 1 || ny < 1 || nx > M || ny > N) { // 경계를 벗어나는 것은 고려 x
        return false;
    }

    nx = x;
    ny = y;

    for (int i = 0; i < k; i++){
        nx = nx + "1120"[d-1] - '1';
        ny = ny + "2011"[d-1] - '1';

        if (robot[nx][ny] == 1) { // 앞으로 k칸 가는 도중에 벽에 막히면 고려 x
            return false;
        }
    }
    return true;
}

int turn_dir(int d, char c){
    // → - 1, ↑ - 4, ← - 2, ↓ - 3
    if (c == 'L'){  // 반시계 방향으로 회전
        switch (d) {
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 1;
        case 4:
            return 2;
        }
    }
    else if (c == 'R') { // 시계 방향으로 회전
        switch (d) {
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 2;
        case 4:
            return 1;
        }
    }
}

void bfs(int a, int b, int c){
    queue < pair<pair<int, int>, pair<int, int>>> Q;
    Q.push(make_pair(make_pair(a, b), make_pair(c, 0)));
    visited[a][b][c] = true; // 맨 처음 위치는 방문한걸로 처리

    while (!Q.empty()){
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int d = Q.front().second.first;
        int ans = Q.front().second.second;
        Q.pop();

        if (x == to.front().first.first && y == to.front().first.second && d == to.front().second){ // 도착점에 도착했을 때
            cout << ans << "\n";
            return;
        }

        for (int i = 1; i <= 3; i++){   //최대 3칸까지 움직일수 있으므로
            if (go_k(x, y, d, i) == true){
                int nx = x + ("1120"[d - 1] - '1') * i;
                int ny = y + ("2011"[d - 1] - '1') * i;

                if (visited[nx][ny][d] == false){ // 방문을 안했을때만  true로 바꾸고 q에 넣어준다.
                    visited[nx][ny][d] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(d, ans + 1))); // ans값을 증가시켜주고 다시 q에 넣는다.
                }
            }
        }

        int nd;
        nd = turn_dir(d, 'L'); // 반시계 방향으로 회전
        if (visited[x][y][nd] == false){  // 회전 후 방문 가능하면 방문해주고 q에 넣는다.
            visited[x][y][nd] = true;
            Q.push(make_pair(make_pair(x, y), make_pair(nd, ans + 1)));
        }

        nd = turn_dir(d, 'R'); // 시계 방향으로 회전
        if (visited[x][y][nd] == false){ // 회전 후 방문 가능하면 방문해주고 q에 넣는다.
            visited[x][y][nd] = true;
            Q.push(make_pair(make_pair(x, y), make_pair(nd, ans + 1)));
        }
    }
}
int main() {
    cin >> M >> N;
    for (int i = 1; i <= M; i++){
        for (int j = 1; j <= N; j++){
            cin >> robot[i][j];
        }
    }
    int a, b, c;
    cin >> a >> b >> c;
    from.push_back(make_pair(make_pair(a, b), c)); // 시작점 설정
    cin >> a >> b >> c;
    to.push_back(make_pair(make_pair(a, b), c)); // 도착점 설정
    int x = from.front().first.first;
    int y = from.front().first.second;
    int d = from.front().second;
    bfs(x, y, d);
    return 0;
}