#include <iostream>
#include <deque>
using namespace std;
int arr[5000001];
deque<pair<int, int>> dq; // value, idx
int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(NULL);
    cin.tie(0); 

    int N, L;
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++) {
        //dq���� �ִ� L���� ���� ����
        if (!dq.empty() && dq.front().second <= i - L) {
            dq.pop_front();
        }
        // ���� �ͺ��� ũ�Ⱑ ū �͵��� �� pop��.
        // �̷��� �ϸ� �� ����(front)�� ���� �� �ּڰ��� �ְ� �ȴ�.
        while (!dq.empty() && dq.back().first > arr[i]) {
            dq.pop_back();
        }
        // (value, index) ���� ����
        dq.push_back(make_pair(arr[i], i));
        cout << dq.front().first << " ";
    }
    return 0;
}