#include <iostream>
#include <memory.h>
using namespace std;
int arr[1001][2], n, k, fuel;
bool visited[1001];
int distance(int a, int b, int c, int d) {
    return ((a - c) * (a - c) + (b - d) * (b - d));
}
bool dfs(int i, int cnt) {
    if (!cnt) {
        return false;
    }
    visited[i] = true;
    for (int j = 1; j <= n; j++) {
        // �̹� �湮���� ��쿡�� false, ���� ���������� ���� ���ᷮ���� �� �� ������ false
        if ((!visited[j] && distance(arr[i][0], arr[i][1], arr[j][0], arr[j][1]) <= fuel) && (distance(arr[j][0], arr[j][1], 10000, 10000) <= fuel || dfs(j, cnt - 1))) {
            return true;
        }
    }
    return false;
}

int main() {
    // n : ������ �� , k : �߰��� ������ ������ �޴� �ִ� Ƚ�� 
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        // ������(������)�� x,y ��ǥ
        cin >> arr[i][0] >> arr[i][1];
    }
    // high�� 10000 x ��Ʈ2 (�밢��)�� �ٻ簪�� 15000���� ����
    int low = 1, high = 15000, mid;
    while (low <= high) {
        memset(visited, 0, sizeof(visited));
        mid = (low + high) / 2;
        // a^2 + b^2 = c^2 �������Ƿ�, ���� fuel = mid * 10�ε� ��������
        fuel = mid * mid * 100;
        if (dfs(0, k)) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    cout << low;
}