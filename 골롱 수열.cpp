#include <iostream>
using namespace std;
int arr[1000000]; // ũ�� �鸸�̸� �����
int main() {
    int n, i;
    cin >> n;
    if (n == 1) {
        cout << "1";
        return 0;
    }
    arr[1] = 1;
    int sum = arr[1];
    for (i = 2; i <= n; i++) {
        // ��� ���� ��ȭ�� 
        arr[i] = 1 + arr[i - arr[arr[i - 1]]];
        sum += arr[i];
        // sum���� ����ؼ� ��� ������ f(i)���� ���� �ְ� �ᱹ sum�� n�� ������
        // �׶� i���� n�϶� f(n)�� ���� �ȴ�.
        if (sum >= n) {
            break;
        }
    }
    cout << i;
    return 0;
}