#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <cstring>
using namespace std;

int N, M, Area_Num, Answer = INT_MAX;
int map[10][10];                    // �Է� ���� ��
int Label[10][10];                // �� ������ ��ȣ�� ���̱� ���� ����� ��
int Dist[7][7];    // �� ���� �ִܰŸ��� �����ϱ� ���� �迭.  Dist[a][b] = C : a�� b�� �ִܰŸ��� c

bool visited[10][10];                    // BFSŽ�� ��, �湮üũ�� ���� �迭(���� ��ȣ ���� �� ���)
bool Connect[7][7];    // ������� üũ�� ���� �迭
bool ConnectIsland[7];            // BFSŽ�� ��, �湮üũ�� ���� �迭(������踦 ����, ������ �����ϱ� ���� BFSŽ�� �� ���)
bool Select[7 * 7];    // ���� ���⿡�� �ߺ� ������ ���� ���� �迭.
/* Select�迭�� ũ�� : 7 * 7
   - ���� N�� �����ϰ�, �� ������ �����Ѵٰ� �������� ��
     ���� �� �ִ� ������ �ִ� ������ N(N-1)/2 �� �Դϴ�
*/

vector<pair<int, int>> V;                      // �Է� ��, ��� ���� ��ǥ���� �����ϱ� ���� ����
vector<pair<int, int>> Area_Pos[10 + 1];     // �� ���� �����ϴ� ���� ��ǥ���� �����ϱ� ���� ���͹迭
vector<pair<pair<int, int>, int>> BridgeList; // ���� ���� �����ϴ� �ٸ��� ���̿�, �� �ٸ��� � ���� �����ϴ��� �����ϱ� ���� ����.

void BFS(int a, int b, int Num) {
    /*
       ����� ���� Ž���ϸ鼭 ��ȣ�� ���̴� �Լ�.
       (a, b) = Ž���� ������ ù ������ ��ǥ.
       Num = Ž���� ������ ���� �� ��ȣ.
    */
    queue<pair<int, int>> Q;
    Q.push(make_pair(a, b));
    visited[a][b] = true; // �湮�ߴٰ� �ٲ��ְ�
    Label[a][b] = Num; // (a,b)�� �� ��ȣ�� label�迭�� �־���
    Area_Pos[Num].push_back(make_pair(a, b));
    /*
       �������� ���ߵ���, ���� ��ȣ�� ���̸鼭 ���ÿ�
       �� ���� �����ϴ� ������� ��ǥ���� ���͹迭�� �������ش�.
       �� ���͹迭��, �� �� ���鰣�� �ִܰŸ��� ���ϴµ� ���.
    */

    while (Q.empty() == 0) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + "1120"[i] - '1';
            int ny = y + "2011"[i] - '1';
            if (nx >= 0 && ny >= 0 && nx < N && ny < M) { // ������ ���� ������
                if (visited[nx][ny] == false && map[nx][ny] == 1) {// �湮���� �ʾҰ� �� ��ǥ�� ���̶��
                    visited[nx][ny] = true;
                    Label[nx][ny] = Num;
                    Q.push(make_pair(nx, ny));
                    Area_Pos[Num].push_back(make_pair(nx, ny)); // area_pos���� �־���
                }
            }
        }
    }
}

void MakeLabel() {
    /*
        ���� ��ȣ�� ���̴� �Լ�
        �Է� �� ������ ���� Vector�� ���������� Ž���ϸ鼭
        ���� �湮���� ���� ��ǥ�鿡 ���ؼ��� BFS Ž�� �ǽ�.
    */
    int LabelNum = 1;
    for (int i = 0; i < V.size(); i++) {
        int x = V[i].first;
        int y = V[i].second;

        if (visited[x][y] == false) {
            BFS(x, y, LabelNum++);
        }
    }
    Area_Num = LabelNum;    // ���� �������� ���� = Area_Num - 1
}

void DFS(int x, int y, int dir, int B_Size, int Start, int End)
{
    int nx = x + "1120"[dir] - '1';
    int ny = y + "2011"[dir] - '1';
    if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
        return;                // ���� ������ ����� return
    }
    if (map[nx][ny] == 0) {   // ���� �ٴٶ�� ��� Ž��.
        DFS(nx, ny, dir, B_Size + 1, Start, End);
    }
    else if (map[nx][ny] == 1) {                   // Ž���Ϸ��� ������ ���̶��
        if (Label[nx][ny] == End) {               // �� ���� �������̶�� ?
            if (B_Size > 1) {                       // �ٸ��� ���̰� 2�̻����� üũ
                if (Dist[Start][End] > B_Size) {   // �ּұ��̷� ����
                    Dist[Start][End] = B_Size;
                    Dist[End][Start] = B_Size;
                }
                return;
            }
        }
        else {
            return;    // �������� �ƴ� �ٸ� ���̶�� return.
        }
    }
}
void MakeBridge(int Start, int End) {
    /* ���� ���� �����ϴ� ��� ����� �鿡�� ���� ������ Ž���غ���.*/
    for (int i = 0; i < Area_Pos[Start].size(); i++) {
        int x = Area_Pos[Start][i].first;
        int y = Area_Pos[Start][i].second;

        for (int j = 0; j < 4; j++) {
            int nx = x + "1120"[j] - '1';
            int ny = y + "2011"[j] - '1';

            if (nx >= 0 && ny >= 0 && nx < N && ny < M) { // ���� ���̶��
                if (map[nx][ny] == 0) { // ���� ��ǥ�� �ٴٶ��
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

            Connect[x][y] = true;    // ������ �ٸ��� �����ϴ� ������ ������踦 ǥ��
            Connect[y][x] = true;
        }
    }

    // ���� BFSŽ���� ���ؼ� Ž���� �� �ִ� ���� ������ Count.
    queue<int> Q;
    Q.push(1);
    ConnectIsland[1] = true;

    int IslandCnt = 1;
    bool Flag = false;
    while (!Q.empty()) {
        int Cur = Q.front();
        Q.pop();

        if (IslandCnt == Area_Num - 1) { // ��� ���� ����Ǿ��ٸ�
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
    ���鰣�� �ִܰŸ��� ���ϱ� ���� �Լ�.
    �������� ������ ���� ��, DFS�� ���ؼ� ����.
    */
    for (int i = 1; i < Area_Num; i++) {
        for (int j = i + 1; j < Area_Num; j++) {
            MakeBridge(i, j);
            if (Dist[i][j] == INT_MAX) {
                continue;
            }
            BridgeList.push_back(make_pair(make_pair(i, j), Dist[i][j]));
            // �ٸ��� �ּҰŸ��� ��������, BridgeList ���Ϳ� �ٸ��� �����ϴ� 2���� ����, �� �Ÿ� �� 3���� �����͸� ����.
        }
    }
}

void DistDFS(int Idx, int Cnt, int Sum) {
    /* ���� ������ ���ؼ� ������ �����ϱ� ���� �Լ�.*/
    if (Cnt >= 1) {   // 1���̻� �̾����� ������ Ȯ���غ���.
        if (CheckState() == true) {
            if (Answer > Sum) { // �ٸ� ������ �ּڰ����� ����
                Answer = Sum;
            }
        }
    }
    for (int i = Idx; i < BridgeList.size(); i++) {
        if (Select[i] == true) { // �̹� �̾Ҵٸ�
            continue;
        }
        Select[i] = true;
        DistDFS(i, Cnt + 1, Sum + BridgeList[i].second);
        Select[i] = false;
    }
}

int main() {
    for (int i = 0; i < 7; i++) { // ���� ������ 2~6������
        for (int j = 0; j < 7; j++) {
            Dist[i][j] = INT_MAX;
        }
    }
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                V.push_back(make_pair(i, j));    // �Է°� ���ÿ�, ���� ��ǥ���� ��� ����.
            }
        }
    }
    MakeLabel();            // ���� ��ȣ ���̱�
    FindDistance();            // �� ���� �ִܰŸ� ���ϱ�
    DistDFS(0, 0, 0);        // ���� �����ϱ�

    if (Answer == INT_MAX) {
        cout << -1 << "\n";
    }
    else {
        cout << Answer << "\n";
    }
    return 0;
}