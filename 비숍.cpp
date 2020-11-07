#include <iostream>
#include <algorithm>
using namespace std;

int N;
int ans[2]; // ü���ǿ��� ����ǰ� ������ ���� ���� �������
int chess[11][11];
int l[20]; // �֢� ���⿡ ����� ������ �ִ°�. (l �迭�� ǥ��)
int r[20]; // �آ� ���⿡ ����� ������ �ִ°�. (r �迭�� ǥ��)

// ���� �� �ִ� ����� �ִ밳���� ���ϴ� �Լ�
// ��/��, �� ���� ���� ������ ���
void tracking(int row, int col, int count, int color) {
    if (col >= N) { // ���� ������ �ʰ��ϸ� ���� ������ �̵� 
        row++;
        if (col % 2 == 0) {
            col = 1;
        }
        else {
            col = 0;
        }
    }
    if (row >= N) { // ������ Ž���Ѱ��
        ans[color] = max(ans[color], count); // ũ�� ���ؼ� ��������
        return;
    }
    // �֢� ���⿡���� row+col�� ���� ����. (l �迭�� ǥ��)
    // �آ� ���⿡���� col-row�� ���� ����. (r �迭�� ǥ��)
    // �ε��� �κ��� 0���� ������ֱ� ���� N-1�� +���־���.
    if (chess[row][col] && !l[col - row + N - 1] && !r[row + col]) { // chess[row][col]�� ���� 0�� �ƴϰ� �� �밢�� ���⿡ ���� ���°��
        l[col - row + N - 1] = r[row + col] = 1; // �湮 ǥ�� (���� ����)
        tracking(row, col + 2, count + 1, color); // �ش� �ڸ��� ���� ���� ������ Ž����
        l[col - row + N - 1] = r[row + col] = 0; // �ʱ�ȭ 
    }
    tracking(row, col + 2, count, color); // �ش� �ڸ��� ���� ���� �ʰ� ������ Ž����
    // �������� �������ǳ���, ����� ����ǳ��� ����ϱ� ���� col + 2 �� ����
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> chess[i][j];
        }
    }

    tracking(0, 0, 0, 0);
    tracking(0, 1, 0, 1);

    cout << ans[0] + ans[1];

    return 0;
}