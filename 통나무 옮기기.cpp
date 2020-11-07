#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;

int N, ans, finish_direction;
bool flag;
vector <pair<int, int>> start[3];
vector <pair<int, int>> finish[3];
queue<pair<pair<int, int>, int>> q;
int arr[51][51]; 
int visited[51][51][2];

void bfs(){
    while (!q.empty()){
        int q_size = q.size();
        while (q_size--){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            q.pop();
            if (x == finish[1].front().first && y == finish[1].front().second && d == finish_direction) {
                flag = true;
                return;
            }

            for (int i = 0; i < 4; i++){ // 상하좌우
                int mx = x + "02110022"[i] - '1'; // { -1, 1, 0, 0, -1, -1, 1, 1 };
                int my = y + "11020202"[i] - '1'; // { 0, 0, -1, 1, -1, 1, -1, 1 };
                                                  // //  U D L R UL UR DL DR
                // 가로모양
                if (d == 0) {
                    if (mx < 0 || mx >= N || my < 1 || my >= N - 1) { // 이동 하는 곳이 배열에서 벗어나는 경우 제외
                        continue;
                    }
                    if (arr[mx][my - 1] || arr[mx][my] || arr[mx][my + 1]) { // 이동 하는 곳에 1(잘려지지 않은 나무)이 있을 경우 제외
                        continue;
                    }
                }
                // 세로모양
                else {
                    if (mx < 1 || mx >= N - 1 || my < 0 || my >= N) { // 이동 하는 곳이 배열에서 벗어나는 경우 제외
                        continue;
                    }
                    if (arr[mx - 1][my] || arr[mx][my] || arr[mx + 1][my]) { // 이동 하는 곳에 1(잘려지지 않은 나무)이 있을 경우 제외
                        continue;
                    }
                }
                if (visited[mx][my][d]) {  // 이동하려는 곳이 이미 방문한 경우 제외
                    continue;
                }
                visited[mx][my][d] = 1; // 모든 조건이 양호하면 방문했다고 표시한 뒤
                q.push(make_pair(make_pair(mx, my), d)); // vector에 넣어줌
            }

            for (int i = 0; i < 8; i++){ // 회전 시도 (8방향 모두 탐색)
                int mx = x + "02110022"[i] - '1'; 
                int my = y + "11020202"[i] - '1'; 

                if (mx < 0 || mx >= N || my < 0 || my >= N) { // 이동하면 배열에서 벗어나는 경우 제외
                    flag = 1; 
                    break;
                }
                if (arr[mx][my]) { // 이동하는 경로에 1(베어지지 않는 나무)이 있는 경우 제외
                    flag = 1; 
                    break;
                }
            }

            if (!flag){ // 모든 조건이 양호하면
                int md = (d + 1) % 2; // 0(가로 모양) -> 1(세로 모양) , 1(세로 모양) -> 0(가로 모양)으로 바꿔줌
                if (!visited[x][y][md]) { // 가려는 곳이 방문되지 않았다면 
                    visited[x][y][md] = 1; // 방문시켜주고
                    q.push(make_pair(make_pair(x, y), md)); // 큐에 푸쉬푸쉬
                }
            }
            flag = false; // 다시 초기조건으로 돌려줌
        }
        ans++;
    }
    return;
}

int main(){
    string str;
    cin >> N;
    int start_index = 0, finish_index = 0;

    for (int i = 0; i < N; i++){
        cin >> str;
        for (int j = 0; j < N; j++){
            arr[i][j] = str[j];
            if (arr[i][j] == '0' || arr[i][j] == '1') {
                arr[i][j] -= '0';
            }
            else{
                if (arr[i][j] == 'B') {
                    start[start_index++].push_back(make_pair(i, j));
                }
                else if (arr[i][j] == 'E') {
                    finish[finish_index++].push_back(make_pair(i, j));
                }
                arr[i][j] = 0;
            }
        }
    }

    int start_direction = 0;
    // 가로모양 0
    if (start[0].front().first == start[1].front().first) {
        start_direction = 0;
    }
    // 세로모양 1
    else {
        start_direction = 1;
    }

    // 가로모양 0
    if (finish[0].front().first == finish[1].front().first) {
        finish_direction = 0;
    }
    // 세로모양 1
    else {
        finish_direction = 1;
    }
    visited[start[1].front().first][start[1].front().second][start_direction] = true; // 통나무의 가운데 부분을 방문처리
    q.push(make_pair(make_pair(start[1].front().first, start[1].front().second), start_direction)); // 통나무 가운데 부분 푸쉬푸쉬

    bfs();

    if (flag) {
        cout << ans;
    }
    else {
        cout << "0";
    }
    return 0;
}