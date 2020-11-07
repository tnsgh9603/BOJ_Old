#include <iostream>
#include <cmath>
using namespace std;
int main() {
    // �� - 0, �� - 1, �� - 2, �� - 3
    int n;
    cin >> n;
    int pattern[4][1024];
    bool visited[101][101] = { 0, };

    pattern[0][0] = 0; // ù ������ 0 �϶� ó���� �� �迭 ó���� ���� 0�� �־��� 
    pattern[1][0] = 1; // ù ������ 1 �϶� ó���� �� �迭 ó���� ���� 1�� �־���
    pattern[2][0] = 2; // ù ������ 2 �϶� ó���� �� �迭 ó���� ���� 2�� �־���
    pattern[3][0] = 3; // ù ������ 3 �϶� ó���� �� �迭 ó���� ���� 3�� �־���

    // �巡�� Ŀ�� ���� , ���⺰�� 0~10���� ���� ����
    for (int k = 0; k < 4; k++) {
        for (int i = 1; i <= 10; i++) {
            int start = pow(2, i - 1); // pow�Լ��� �������� double�̶� ����ȯ�� ���־���. �����൵ �Ǳ���
            int end = pow(2, i);
            for (int j = start, l = 1; j < end; j++, l += 2) {
                pattern[k][j] = pattern[k][j - l] + 1 == 4 ? 0 : pattern[k][j - l] + 1;
            }
        }
    }

    // �巡�� Ŀ�� �׸���
    int x, y, d, g; 
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> d >> g;
        int end = (int)pow(2, g);
        visited[x][y] = true;

        for (int j = 0; j < end; j++) {
            if (pattern[d][j] == 0) {
                x++;
            }
            else if (pattern[d][j] == 1) {
                y--;
            }
            else if (pattern[d][j] == 2) {
                x--;
            }
            else {
                y++;
            }
            visited[x][y] = true;
        }
    }

    // �迭 Ž��
    int cnt = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (visited[i][j] && visited[i][j + 1] && visited[i + 1][j] && visited[i + 1][j + 1]) {
                cnt++;
            }
        }
    }
    cout << cnt;
}