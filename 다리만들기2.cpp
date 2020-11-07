#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <cstring>
using namespace std;

int N, M, Area_Num, Answer = INT_MAX;
int map[10][10];                    // 입력 받을 맵
int Label[10][10];                // 각 섬마다 번호를 붙이기 위해 사용한 맵
int Dist[7][7];    // 각 섬의 최단거리를 저장하기 위한 배열.  Dist[a][b] = C : a와 b의 최단거리는 c

bool visited[10][10];                    // BFS탐색 시, 방문체크를 위한 배열(섬의 번호 붙일 때 사용)
bool Connect[7][7];    // 연결관계 체크를 위한 배열
bool ConnectIsland[7];            // BFS탐색 시, 방문체크를 위한 배열(연결관계를 통해, 정답을 도출하기 위한 BFS탐색 시 사용)
bool Select[7 * 7];    // 조합 추출에서 중복 추출을 막기 위한 배열.
/* Select배열의 크기 : 7 * 7
   - 섬이 N개 존재하고, 이 섬들을 연결한다고 가정했을 때
     나올 수 있는 간선의 최대 갯수는 N(N-1)/2 개 입니다
*/

vector<pair<int, int>> V;                      // 입력 시, 모든 섬의 좌표들을 저장하기 위한 벡터
vector<pair<int, int>> Area_Pos[10 + 1];     // 각 섬에 존재하는 땅의 좌표들을 저장하기 위한 벡터배열
vector<pair<pair<int, int>, int>> BridgeList; // 섬과 섬을 연결하는 다리의 길이와, 그 다리가 어떤 섬을 연결하는지 저장하기 위한 벡터.

void BFS(int a, int b, int Num) {
    /*
       연결된 땅을 탐색하면서 번호를 붙이는 함수.
       (a, b) = 탐색을 시작할 첫 정점의 좌표.
       Num = 탐색할 땅들의 붙일 섬 번호.
    */
    queue<pair<int, int>> Q;
    Q.push(make_pair(a, b));
    visited[a][b] = true; // 방문했다고 바꿔주고
    Label[a][b] = Num; // (a,b)의 섬 번호를 label배열에 넣어줌
    Area_Pos[Num].push_back(make_pair(a, b));
    /*
       설명에서도 말했듯이, 섬의 번호를 붙이면서 동시에
       각 섬에 존재하는 땅덩어리의 좌표들을 벡터배열에 저장해준다.
       이 벡터배열은, 이 후 섬들간의 최단거리를 구하는데 사용.
    */

    while (Q.empty() == 0) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + "1120"[i] - '1';
            int ny = y + "2011"[i] - '1';
            if (nx >= 0 && ny >= 0 && nx < N && ny < M) { // 범위를 넘지 않으면
                if (visited[nx][ny] == false && map[nx][ny] == 1) {// 방문하지 않았고 그 좌표가 섬이라면
                    visited[nx][ny] = true;
                    Label[nx][ny] = Num;
                    Q.push(make_pair(nx, ny));
                    Area_Pos[Num].push_back(make_pair(nx, ny)); // area_pos에도 넣어줌
                }
            }
        }
    }
}

void MakeLabel() {
    /*
        섬의 번호를 붙이는 함수
        입력 시 저장해 놓은 Vector를 순차적으로 탐색하면서
        아직 방문하지 않은 좌표들에 대해서는 BFS 탐색 실시.
    */
    int LabelNum = 1;
    for (int i = 0; i < V.size(); i++) {
        int x = V[i].first;
        int y = V[i].second;

        if (visited[x][y] == false) {
            BFS(x, y, LabelNum++);
        }
    }
    Area_Num = LabelNum;    // 섬의 최종적인 갯수 = Area_Num - 1
}

void DFS(int x, int y, int dir, int B_Size, int Start, int End)
{
    int nx = x + "1120"[dir] - '1';
    int ny = y + "2011"[dir] - '1';
    if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
        return;                // 맵의 범위를 벗어나면 return
    }
    if (map[nx][ny] == 0) {   // 아직 바다라면 계속 탐색.
        DFS(nx, ny, dir, B_Size + 1, Start, End);
    }
    else if (map[nx][ny] == 1) {                   // 탐색하려는 정점이 땅이라면
        if (Label[nx][ny] == End) {               // 그 땅이 도착섬이라면 ?
            if (B_Size > 1) {                       // 다리의 길이가 2이상인지 체크
                if (Dist[Start][End] > B_Size) {   // 최소길이로 갱신
                    Dist[Start][End] = B_Size;
                    Dist[End][Start] = B_Size;
                }
                return;
            }
        }
        else {
            return;    // 도착점이 아닌 다른 섬이라면 return.
        }
    }
}
void MakeBridge(int Start, int End) {
    /* 시작 섬에 존재하는 모든 땅덩어리 들에서 도착 섬까지 탐색해본다.*/
    for (int i = 0; i < Area_Pos[Start].size(); i++) {
        int x = Area_Pos[Start][i].first;
        int y = Area_Pos[Start][i].second;

        for (int j = 0; j < 4; j++) {
            int nx = x + "1120"[j] - '1';
            int ny = y + "2011"[j] - '1';

            if (nx >= 0 && ny >= 0 && nx < N && ny < M) { // 범위 안이라면
                if (map[nx][ny] == 0) { // 다음 좌표가 바다라면
                    DFS(x, y, j, 0, Start, End);
                }
            }
        }
    }
}

bool CheckState() {
    memset(Connect, false, sizeof(Connect));
    memset(ConnectIsland, false, sizeof(ConnectIsland));
    for (int i = 0; i < BridgeList.size(); i++) {
        if (Select[i] == true) {
            int x = BridgeList[i].first.first; 
            int y = BridgeList[i].first.second; 

            Connect[x][y] = true;    // 선택한 다리가 연결하는 섬들의 연결관계를 표시
            Connect[y][x] = true;
        }
    }

    // 이후 BFS탐색을 통해서 탐색할 수 있는 섬의 갯수를 Count.
    queue<int> Q;
    Q.push(1);
    ConnectIsland[1] = true;

    int IslandCnt = 1;
    bool Flag = false;
    while (!Q.empty()) {
        int Cur = Q.front();
        Q.pop();

        if (IslandCnt == Area_Num - 1) { // 모든 섬이 연결되었다면
            Flag = true;
            break;
        }

        for (int i = 1; i < Area_Num; i++) {
            if (Cur == i) {
                continue;
            }
            if (Connect[Cur][i] == true && ConnectIsland[i] == false) {
                ConnectIsland[i] = true;
                Q.push(i);
                IslandCnt++;
            }
        }
    }
    return Flag;
}

void FindDistance() {
    /*
    섬들간의 최단거리를 구하기 위한 함수.
    시작점과 끝점을 정한 후, DFS를 통해서 구현.
    */
    for (int i = 1; i < Area_Num; i++) {
        for (int j = i + 1; j < Area_Num; j++) {
            MakeBridge(i, j);
            if (Dist[i][j] == INT_MAX) {
                continue;
            }
            BridgeList.push_back(make_pair(make_pair(i, j), Dist[i][j]));
            // 다리의 최소거리를 구했으면, BridgeList 벡터에 다리가 연결하는 2개의 섬과, 그 거리 총 3개의 데이터를 저장.
        }
    }
}

void DistDFS(int Idx, int Cnt, int Sum) {
    /* 조합 구현을 통해서 정답을 도출하기 위한 함수.*/
    if (Cnt >= 1) {   // 1개이상만 뽑았으면 무조건 확인해본다.
        if (CheckState() == true) {
            if (Answer > Sum) { // 다리 길이의 최솟값으로 갱신
                Answer = Sum;
            }
        }
    }
    for (int i = Idx; i < BridgeList.size(); i++) {
        if (Select[i] == true) { // 이미 뽑았다면
            continue;
        }
        Select[i] = true;
        DistDFS(i, Cnt + 1, Sum + BridgeList[i].second);
        Select[i] = false;
    }
}

int main() {
    for (int i = 0; i < 7; i++) { // 섬의 개수는 2~6개까지
        for (int j = 0; j < 7; j++) {
            Dist[i][j] = INT_MAX;
        }
    }
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                V.push_back(make_pair(i, j));    // 입력과 동시에, 섬의 좌표들은 모두 저장.
            }
        }
    }
    MakeLabel();            // 섬의 번호 붙이기
    FindDistance();            // 섬 끼리 최단거리 구하기
    DistDFS(0, 0, 0);        // 정답 도출하기

    if (Answer == INT_MAX) {
        cout << -1 << "\n";
    }
    else {
        cout << Answer << "\n";
    }
    return 0;
}