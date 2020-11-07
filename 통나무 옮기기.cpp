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

            for (int i = 0; i < 4; i++){ // �����¿�
                int mx = x + "02110022"[i] - '1'; // { -1, 1, 0, 0, -1, -1, 1, 1 };
                int my = y + "11020202"[i] - '1'; // { 0, 0, -1, 1, -1, 1, -1, 1 };
                                                  // //  U D L R UL UR DL DR
                // ���θ��
                if (d == 0) {
                    if (mx < 0 || mx >= N || my < 1 || my >= N - 1) { // �̵� �ϴ� ���� �迭���� ����� ��� ����
                        continue;
                    }
                    if (arr[mx][my - 1] || arr[mx][my] || arr[mx][my + 1]) { // �̵� �ϴ� ���� 1(�߷����� ���� ����)�� ���� ��� ����
                        continue;
                    }
                }
                // ���θ��
                else {
                    if (mx < 1 || mx >= N - 1 || my < 0 || my >= N) { // �̵� �ϴ� ���� �迭���� ����� ��� ����
                        continue;
                    }
                    if (arr[mx - 1][my] || arr[mx][my] || arr[mx + 1][my]) { // �̵� �ϴ� ���� 1(�߷����� ���� ����)�� ���� ��� ����
                        continue;
                    }
                }
                if (visited[mx][my][d]) {  // �̵��Ϸ��� ���� �̹� �湮�� ��� ����
                    continue;
                }
                visited[mx][my][d] = 1; // ��� ������ ��ȣ�ϸ� �湮�ߴٰ� ǥ���� ��
                q.push(make_pair(make_pair(mx, my), d)); // vector�� �־���
            }

            for (int i = 0; i < 8; i++){ // ȸ�� �õ� (8���� ��� Ž��)
                int mx = x + "02110022"[i] - '1'; 
                int my = y + "11020202"[i] - '1'; 

                if (mx < 0 || mx >= N || my < 0 || my >= N) { // �̵��ϸ� �迭���� ����� ��� ����
                    flag = 1; 
                    break;
                }
                if (arr[mx][my]) { // �̵��ϴ� ��ο� 1(�������� �ʴ� ����)�� �ִ� ��� ����
                    flag = 1; 
                    break;
                }
            }

            if (!flag){ // ��� ������ ��ȣ�ϸ�
                int md = (d + 1) % 2; // 0(���� ���) -> 1(���� ���) , 1(���� ���) -> 0(���� ���)���� �ٲ���
                if (!visited[x][y][md]) { // ������ ���� �湮���� �ʾҴٸ� 
                    visited[x][y][md] = 1; // �湮�����ְ�
                    q.push(make_pair(make_pair(x, y), md)); // ť�� Ǫ��Ǫ��
                }
            }
            flag = false; // �ٽ� �ʱ��������� ������
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
    // ���θ�� 0
    if (start[0].front().first == start[1].front().first) {
        start_direction = 0;
    }
    // ���θ�� 1
    else {
        start_direction = 1;
    }

    // ���θ�� 0
    if (finish[0].front().first == finish[1].front().first) {
        finish_direction = 0;
    }
    // ���θ�� 1
    else {
        finish_direction = 1;
    }
    visited[start[1].front().first][start[1].front().second][start_direction] = true; // �볪���� ��� �κ��� �湮ó��
    q.push(make_pair(make_pair(start[1].front().first, start[1].front().second), start_direction)); // �볪�� ��� �κ� Ǫ��Ǫ��

    bfs();

    if (flag) {
        cout << ans;
    }
    else {
        cout << "0";
    }
    return 0;
}