#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N;
int robot[101][101]; 
bool visited[101][101][5]; // �湮�� �� üũ
vector<pair<pair<int, int>, int >> from, to;

bool go_k(int x, int y, int d, int k){
    int nx = x + ("1120"[d - 1] - '1') * k; // k�� �ִ� 3
    int ny = y + ("2011"[d - 1] - '1') * k;

    if (nx < 1 || ny < 1 || nx > M || ny > N) { // ��踦 ����� ���� ��� x
        return false;
    }

    nx = x;
    ny = y;

    for (int i = 0; i < k; i++){
        nx = nx + "1120"[d-1] - '1';
        ny = ny + "2011"[d-1] - '1';

        if (robot[nx][ny] == 1) { // ������ kĭ ���� ���߿� ���� ������ ��� x
            return false;
        }
    }
    return true;
}

int turn_dir(int d, char c){
    // �� - 1, �� - 4, �� - 2, �� - 3
    if (c == 'L'){  // �ݽð� �������� ȸ��
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
    else if (c == 'R') { // �ð� �������� ȸ��
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
    visited[a][b][c] = true; // �� ó�� ��ġ�� �湮�Ѱɷ� ó��

    while (!Q.empty()){
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int d = Q.front().second.first;
        int ans = Q.front().second.second;
        Q.pop();

        if (x == to.front().first.first && y == to.front().first.second && d == to.front().second){ // �������� �������� ��
            cout << ans << "\n";
            return;
        }

        for (int i = 1; i <= 3; i++){   //�ִ� 3ĭ���� �����ϼ� �����Ƿ�
            if (go_k(x, y, d, i) == true){
                int nx = x + ("1120"[d - 1] - '1') * i;
                int ny = y + ("2011"[d - 1] - '1') * i;

                if (visited[nx][ny][d] == false){ // �湮�� ����������  true�� �ٲٰ� q�� �־��ش�.
                    visited[nx][ny][d] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(d, ans + 1))); // ans���� ���������ְ� �ٽ� q�� �ִ´�.
                }
            }
        }

        int nd;
        nd = turn_dir(d, 'L'); // �ݽð� �������� ȸ��
        if (visited[x][y][nd] == false){  // ȸ�� �� �湮 �����ϸ� �湮���ְ� q�� �ִ´�.
            visited[x][y][nd] = true;
            Q.push(make_pair(make_pair(x, y), make_pair(nd, ans + 1)));
        }

        nd = turn_dir(d, 'R'); // �ð� �������� ȸ��
        if (visited[x][y][nd] == false){ // ȸ�� �� �湮 �����ϸ� �湮���ְ� q�� �ִ´�.
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
    from.push_back(make_pair(make_pair(a, b), c)); // ������ ����
    cin >> a >> b >> c;
    to.push_back(make_pair(make_pair(a, b), c)); // ������ ����
    int x = from.front().first.first;
    int y = from.front().first.second;
    int d = from.front().second;
    bfs(x, y, d);
    return 0;
}