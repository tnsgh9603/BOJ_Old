#include <iostream>
#include <algorithm> // sort �Լ� ���� ����
#include <queue> // FIFO (first in first out)
using namespace std;
priority_queue <int> pq;
pair<int, int> arr[10001];
int main() {
    int n, l, p, i = 0, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    cin >> l >> p; // l : �������� ��ġ���� �������� �Ÿ�, p : Ʈ���� ���� �ִ� ������ ��

    // (�����ұ����� �Ÿ�, �����ҿ��� ä�� �� �ִ� �����) �������� ����
    sort(arr, arr + n);

    // ������ ������ �ݺ�
    while (p < l) {
        // ���� �����ұ����� �Ÿ��� ���� ���ᷮ���� �� �� ���� ���
        while (arr[i].first <= p) {
            // �� �� �ִ� ��� �����Ҹ� �湮������ break
            if (i == n) {
                break;
            }
            // ���� �����ҿ��� ä�� �� �ִ� ���� ���� push
            pq.push(arr[i].second);
            i++;
        }
        // �� �� �ִ� ��� �����Ҹ� �湮������ break
        if (pq.empty()) {
            break;
        }
        // cnt : ������ �鸰 Ƚ�� 
        cnt++;
        // ���Ḧ ä�� ��� ���� ���ᷮ���� +����
        p += pq.top();
        pq.pop();
    }
    // ������ ���������� ������ �鸰 Ƚ���� ����ϰ� ���� �������� -1 ���
    int ans = (p < l) ? -1 : cnt;
    cout << ans;
    return 0;
}