#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N, M, K;
int ans = 1;
bool flag;

queue <pair<pair<int, int>,int>> q;
int map[1001][1001];
bool visited[1001][1001][11]; // �湮�ߴٴ°��� ǥ��

int main(){
    string str;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++){
        cin >> str;
        for (int j = 1; j <= M; j++){
            map[i][j] = str[j - 1] - '0'; // string���� �޾������� - '0' ����
        }
    }

    q.push(make_pair(make_pair(1, 1), 0));
    visited[1][1][0] = true;

    while (!q.empty()){ // q�� �� ������
        int qsize = q.size();
        while (qsize--){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int gowall = q.front().second;
            q.pop();

            if (x == N && y == M){ // ���������� break;
                flag = true;
                break;
            }

            for (int i = 0; i < 4; i++){
                int mx = x + "1102"[i] - '1';
                int my = y + "2011"[i] - '1';
                int ngowall = map[mx][my]; // 1�̸� ���� �ν��� �� �� �ִ�.

                if (mx >= 1 && mx <= N && my >= 1 && my <= M){ // �迭 ������ �ʰ� ���������� ���
                    if ((gowall + ngowall) > K) { // ���� k������ �μ� �� �ִ�. k���� �Ѿ�� continue
                        continue;
                    }
                    ngowall += gowall; // �� �μ� ȸ�� �߰�
                    if (visited[mx][my][ngowall]) { // �湮 �߾��ٸ� ����
                        continue;
                    }
                    // �湮 �������� �湮 ǥ�� �� Ǫ��Ǫ��
                    q.push(make_pair(make_pair(mx, my), ngowall)); 
                    visited[mx][my][ngowall] = true;
                }
            }
        }
        if (flag) {
            break;
        }
        else {
            ans++;
        }
    }

    if (flag) {
        cout << ans;
    }
    else {
        cout << -1;
    }
    return 0;
}