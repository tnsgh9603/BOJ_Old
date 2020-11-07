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
        //dq에는 최대 L개의 값이 저장
        if (!dq.empty() && dq.front().second <= i - L) {
            dq.pop_front();
        }
        // 넣을 것보다 크기가 큰 것들은 다 pop함.
        // 이렇게 하면 맨 왼쪽(front)에 구간 내 최솟값이 있게 된다.
        while (!dq.empty() && dq.back().first > arr[i]) {
            dq.pop_back();
        }
        // (value, index) 값을 넣음
        dq.push_back(make_pair(arr[i], i));
        cout << dq.front().first << " ";
    }
    return 0;
}