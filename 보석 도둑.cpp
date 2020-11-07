#include <iostream>
#include <queue> // FIFO
#include <algorithm> // sort 함수를 위해
using namespace std;

pair<int, int> jewelry[300000]; // 보석의 무게와 가치를 저장
priority_queue<int> pq; 
int bag[300000]; // 가방의 최대 무게 저장

int main() {
    int n, k, j = 0;
    // n : 보석 갯수 , k : 가방 갯수
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        // 첫 번째 요소에는 보석의 무게를, 두 번째 요소에는 보석의 가치를 저장한다.
        cin >> jewelry[i].first >> jewelry[i].second;
    }
    for (int i = 0; i < k; i++) {
        cin >> bag[i]; // 가방의 최대 무게 저장 
    }

    // 오름차순 정렬
    sort(jewelry, jewelry + n);
    sort(bag, bag + k);

    long long sum = 0;  // 보석의 최대 개수 <= 300000 , 보석의 최대 가치 <= 1,000,000 이므로 
                        // int형의 범위를 넘어갈 수 있기 때문에 long long의 자료형으로 선언 해줘야 한다.
    for (int i = 0, j = 0; i < k; i++) {
        // 모든 보석들에 대해, 가방에 넣을 수 있다면 push
        // 제일 무게가 작은 보석부터 시작
        // 가방의 최대 무게로는 해당 무게의 보석을 못 담으면 지금 가방보다 무게가 큰 것중 가장 작은 가방을 다시 불러옴
        while (j < n && jewelry[j].first <= bag[i]) {
            pq.push(jewelry[j].second);
            j++;
        }
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum;
    return 0;
}