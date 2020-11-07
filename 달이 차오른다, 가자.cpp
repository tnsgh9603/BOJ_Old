#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int N, M;
char arr[51][51];
bool visited[51][51][1 << 6];
pair<int, int> start; // ���� ���� ����
bool have_key(int current_key_state, char door) {
    // ��Ʈ�� & �������� ���� �´� Ű�� �ִ��� Ȯ�� 
    // Ű�� �ִٸ� true ��ȯ
    if (current_key_state & (1 << (int(door) - 'A'))) {
        return true;
    }
    // Ű�� ���ٸ� false ��ȯ
    return false;
}
int bfs(int a, int b) {
    queue <pair<pair<int, int>, pair<int, int>>> q; // ( (���� ������ x��, ���� ������ y��), (�̵� Ƚ��, � Ű�� ������ �ִ���?) ) �� ����
    q.push(make_pair(make_pair(a, b), make_pair(0, 0)));
    visited[a][b][0] = true;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        int key = q.front().second.second;
        q.pop();

        // �ⱸ�� �����ߴٸ� ���� ��Ŵ
        if (arr[x][y] == '1') {
            return cnt;
        }
        for (int i = 0; i < 4; i++) {
            // �����¿� ���� �̵�
            int nx = x + "1120"[i] - '1';
            int ny = y + "2011"[i] - '1';

            // �迭�� ������ ����� �ʴ� �ѿ��� ����
            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                // �湮���� �ʾҴٸ�
                if (!visited[nx][ny][key]) {
                    // �� ���� �� ���̰ų� �ⱸ���
                    if (arr[nx][ny] == '.' || arr[nx][ny] == '1') {
                        // �湮�ߴٰ� ǥ�����ְ�
                        visited[nx][ny][key] = true;
                        // �̵�Ƚ�� +1�� �� �ٽ� ť�� �־���
                        q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, key)));
                    }
                    // �� ���� Ű�� �ִ� ���̶��
                    else if ('a' <= arr[nx][ny] && arr[nx][ny] <= 'f') {
                        // temp_key�� ���� Ű�� ��� �ִ� ���¸� ������
                        int temp_key = key | (1 << (int(arr[nx][ny] - 'a')));
                        // �ش� ��ġ�� �湮�ߴٰ� ǥ��
                        visited[nx][ny][temp_key] = true;
                        // �̵�Ƚ�� +1 �ϰ� Ű ���¸� ���� ��, �ٽ� ť�� �־���
                        q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, temp_key)));
                    }
                    // �� ���� ���̶��
                    else if ('A' <= arr[nx][ny] && arr[nx][ny] <= 'F') {
                        // �ش� ���� �´� Ű�� �ִ��� Ȯ�� �� 
                        if (have_key(key, arr[nx][ny])) {
                            // Ű�� ������ �湮�ߴٰ� ǥ��
                            visited[nx][ny][key] = true;
                            // �̵� Ƚ�� +1 �� �� ť�� �־���
                            q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, key)));
                        }
                        // �ش� ���� �´� Ű�� ������ �ƹ��͵� ���� ����
                    }
                }
            }
        }
    }
    // �ⱸ�� ������ �� ���ٸ� -1�� ����
    return -1;
}
int main() {
    string s;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            arr[i][j] = s[j];
            //���� ���� ����
            if (arr[i][j] == '0') {
                start.first = i;
                start.second = j;
                // ���� �� .(�� ��)�� ǥ�� �ٲ�
                arr[i][j] = '.';
            }
        }
    }
    cout << bfs(start.first, start.second);
    return 0;
}