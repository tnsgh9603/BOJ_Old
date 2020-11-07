#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int N, M;
char arr[51][51];
bool visited[51][51][1 << 6];
pair<int, int> start; // 시작 지점 저장
bool have_key(int current_key_state, char door) {
    // 비트의 & 연산으로 문에 맞는 키가 있는지 확인 
    // 키가 있다면 true 반환
    if (current_key_state & (1 << (int(door) - 'A'))) {
        return true;
    }
    // 키가 없다면 false 반환
    return false;
}
int bfs(int a, int b) {
    queue <pair<pair<int, int>, pair<int, int>>> q; // ( (시작 지점의 x축, 시작 지점의 y축), (이동 횟수, 어떤 키를 가지고 있는지?) ) 를 저장
    q.push(make_pair(make_pair(a, b), make_pair(0, 0)));
    visited[a][b][0] = true;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        int key = q.front().second.second;
        q.pop();

        // 출구에 도착했다면 종료 시킴
        if (arr[x][y] == '1') {
            return cnt;
        }
        for (int i = 0; i < 4; i++) {
            // 상하좌우 방향 이동
            int nx = x + "1120"[i] - '1';
            int ny = y + "2011"[i] - '1';

            // 배열의 범위를 벗어나지 않는 한에서 실행
            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                // 방문하지 않았다면
                if (!visited[nx][ny][key]) {
                    // 갈 곳이 빈 곳이거나 출구라면
                    if (arr[nx][ny] == '.' || arr[nx][ny] == '1') {
                        // 방문했다고 표기해주고
                        visited[nx][ny][key] = true;
                        // 이동횟수 +1한 후 다시 큐에 넣어줌
                        q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, key)));
                    }
                    // 갈 곳이 키가 있는 곳이라면
                    else if ('a' <= arr[nx][ny] && arr[nx][ny] <= 'f') {
                        // temp_key에 현재 키를 들고 있는 상태를 갱신함
                        int temp_key = key | (1 << (int(arr[nx][ny] - 'a')));
                        // 해당 위치를 방문했다고 표시
                        visited[nx][ny][temp_key] = true;
                        // 이동횟수 +1 하고 키 상태를 갱신 후, 다시 큐에 넣어줌
                        q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, temp_key)));
                    }
                    // 갈 곳이 문이라면
                    else if ('A' <= arr[nx][ny] && arr[nx][ny] <= 'F') {
                        // 해당 문에 맞는 키가 있는지 확인 후 
                        if (have_key(key, arr[nx][ny])) {
                            // 키가 있으면 방문했다고 표시
                            visited[nx][ny][key] = true;
                            // 이동 횟수 +1 한 후 큐에 넣어줌
                            q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, key)));
                        }
                        // 해당 문에 맞는 키가 없으면 아무것도 하지 않음
                    }
                }
            }
        }
    }
    // 출구에 도착할 수 없다면 -1을 리턴
    return -1;
}
int main() {
    string s;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            arr[i][j] = s[j];
            //시작 지점 저장
            if (arr[i][j] == '0') {
                start.first = i;
                start.second = j;
                // 저장 후 .(빈 곳)로 표기 바꿈
                arr[i][j] = '.';
            }
        }
    }
    cout << bfs(start.first, start.second);
    return 0;
}