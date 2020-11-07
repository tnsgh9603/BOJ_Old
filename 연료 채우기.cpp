#include <iostream>
#include <algorithm> // sort 함수 쓰기 위해
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
    cin >> l >> p; // l : 성경이의 위치에서 마을까지 거리, p : 트럭에 원래 있던 연료의 양

    // (주유소까지의 거리, 주유소에서 채울 수 있는 연료양) 오름차순 정렬
    sort(arr, arr + n);

    // 도착할 때까지 반복
    while (p < l) {
        // 다음 주유소까지의 거리가 현재 연료량으로 갈 수 있을 경우
        while (arr[i].first <= p) {
            // 갈 수 있는 모든 주유소를 방문했으면 break
            if (i == n) {
                break;
            }
            // 다음 주유소에서 채울 수 있는 연료 양을 push
            pq.push(arr[i].second);
            i++;
        }
        // 갈 수 있는 모든 주유소를 방문했으면 break
        if (pq.empty()) {
            break;
        }
        // cnt : 주유소 들린 횟수 
        cnt++;
        // 연료를 채운 경우 원래 연료량에서 +해줌
        p += pq.top();
        pq.pop();
    }
    // 마을에 도착했으면 주유소 들린 횟수를 출력하고 도착 못했으면 -1 출력
    int ans = (p < l) ? -1 : cnt;
    cout << ans;
    return 0;
}